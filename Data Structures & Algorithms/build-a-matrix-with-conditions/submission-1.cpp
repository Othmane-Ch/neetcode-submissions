class Solution {
public:
    // Time  : O(K² + (K + R)+ (K + C))
    // Space : O(K² + R + C)
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> indegreeRows(k);
        vector<int> indegreeCols(k);
        vector<vector<int>> adjRows(k);
        vector<vector<int>> adjCols(k);
        for(const auto& rowCond : rowConditions)
        {
            ++indegreeRows[rowCond[1] - 1];
            adjRows[rowCond[0] - 1].push_back(rowCond[1] - 1);
        }

        for(const auto& colCond : colConditions)
        {
            ++indegreeCols[colCond[1] - 1];
            adjCols[colCond[0] - 1].push_back(colCond[1] - 1);
        }

        queue<int> qRows {};
        queue<int> qCols {};
        for(int i = 0; i < k; ++i)
        {
            if(!indegreeRows[i])
            {
                qRows.push(i);
            }
            if(!indegreeCols[i])
            {
                qCols.push(i);
            }
        }

        vector<int> orderRows {};
        while(!qRows.empty())
        {
            auto u = qRows.front(); qRows.pop();
            orderRows.push_back(u);
            for(const auto& v : adjRows[u])
            {
                if(--indegreeRows[v] == 0)
                {
                    qRows.push(v);
                }
            }
        }

        if(orderRows.size() != k) return {};
        vector<int> orderCols {};
        while(!qCols.empty())
        {
            auto u = qCols.front(); qCols.pop();
            orderCols.push_back(u);
            for(const auto& v : adjCols[u])
            {
                if(--indegreeCols[v] == 0)
                {
                    qCols.push(v);
                }
            }
        }
        if(orderCols.size() != k) return {};
        vector<int> rowPos(k);
        vector<int> colPos(k);
        for(int i = 0; i < k; ++i)
        {
            rowPos[orderRows[i]] = i;
            colPos[orderCols[i]] = i;
        }
        vector<vector<int>> result(k, vector(k, 0));

        for(int i = 0; i < k; ++i)
        {
            int r = rowPos[i], c = colPos[i];
            result[r][c] = i + 1;
        }

        return result;
    }
};