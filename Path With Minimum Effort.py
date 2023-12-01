/**
 * @param {number[][]} heights
 * @return {number}
 */
var minimumEffortPath = function(H) {
    let y = H.length, x = H[0].length,
        vis = new Uint8Array(x*y),
        effort = new Uint32Array(x*y).fill(1000001), 
        node = 0, path = 0, i, j, cell,
        pq = new MinPriorityQueue({priority: x => x[1]})

    const insert = (next, k, l) => {
        let newEff = Math.max(path, Math.abs(cell - H[k][l]))
        if (effort[next] <= newEff) return
        effort[next] = newEff
        pq.enqueue([next, effort[next]])
    }

    while (node !== x*y-1) {
        i = ~~(node / x), j = node % x, cell = H[i][j]
        if (i > 0 && !vis[node-x]) insert(node-x, i-1, j)
        if (i < y-1 && !vis[node+x]) insert(node+x, i+1, j)
        if (j > 0 && !vis[node-1]) insert(node-1, i, j-1)
        if (j < x-1 && !vis[node+1]) insert(node+1, i, j+1)
        vis[node] = 1
        while (vis[node]) [node, path] = pq.dequeue().element
    }
    return path
};

