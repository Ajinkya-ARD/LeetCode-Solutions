class Solution 
{
public:
    vector<int> asteroidCollision(vector<int> &m_asteroids) 
    {
        vector<int> result;
        
        for(int i = 0; i < m_asteroids.size(); i++)
        {
            if(!result.empty() && result.back() > 0 && m_asteroids[i] < 0)
            {

                while(!result.empty() && result.back() > 0) 
                {
                    if(result.back() + m_asteroids[i] < 0) 
                    {
                        result.pop_back();
                    }
                    else if(result.back() + m_asteroids[i] == 0) 
                    {
                        result.pop_back();
                        m_asteroids[i] = 0;
                        break;
                    }
                    else if(result.back() + m_asteroids[i] > 0) 
                    {
                        m_asteroids[i] = 0;
                        break;
                    }
                }
                
                if(m_asteroids[i] != 0) result.push_back(m_asteroids[i]);
            }
            else
            {
                result.push_back(m_asteroids[i]); 
            }
        }
        
        return result;
    }
};