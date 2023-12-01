/**
 * @param {string[][]} tickets
 * @return {string[]}
 */
var findItinerary = function(tickets) {
    const flight_paths = new Map();

    // This is what we will return, we always know we start at JFK.
    const flight_path_order = ["JFK"];

    tickets = tickets.sort(); // O(n^2);

    // Create the adjacency list.
    for (const [source, dest] of tickets) {
        let edges = [];
        if (flight_paths.has(source)) {
            edges = flight_paths.get(source);
        }
        edges.push(dest);
        flight_paths.set(source, edges);
    }

    // Depth first search.
    const depth_first_search = (city) => {
        // Have we already been to all the nodes?
        // Meaning we have visited all the tickets?
        if (flight_path_order.length === tickets.length + 1) return true;

        // Get the departures of flights from this city.
        // If their isn't any, we need to back track on this node
        // Because we know we have more flights to go and we have already
        // somehow visited our destination. Which is incorrect.
        const cities_to_go_to = flight_paths.get(city) || [];
        if (!cities_to_go_to.length) return false;

        // So we have other cities to go to from here.
        // Let's create a copy of those cities because we're going to
        // be dynamically adding and removing from that array. Something our
        // for loop wouldn't be able able to handle otherwise.
        const cities_copied = Array.from(cities_to_go_to);

        // Visit all connecting cities.
        for (const other_city of cities_copied) {
            // Add to our output, as we're doing this in topological sort
            flight_path_order.push(other_city);

            // Remove the city from the edges of the graph.
            // As we don't want to revisit it. Otherwise we would have a loop.
            // Note: we're passing this array by reference. So we don't need to re-set it.
            // We use shift here because we've done this in lexicographical order starting from
            // the beginning.
            cities_to_go_to.shift();

            // If it returns true, it mean's we've visited all cities
            // and that mean's we have nothing else to do.
            if (depth_first_search(other_city)) {
                return flight_path_order;
            } else {
                // BACKTRACKING!
                // We've visited the wrong city!
                // Undo our work here, as this is not the right city,
                // we need to revisit this city later on and not now.
                // What this does is visit all other cities
                // then backtrack on this city.
                flight_path_order.pop();
                cities_to_go_to.push(other_city);
            }
        }

        return false;
    };

    // Start at JFK airport
    return depth_first_search("JFK");
};