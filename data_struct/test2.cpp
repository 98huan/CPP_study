
void DFS(int m,int n,vector<int>& end,vector<vector<int>>& obstacle,int i, int j,int k,vector<vector<int>>& visited,int len,int& minlen,int& count) {
     //判断当前位置是否超过边界
     if (i < 0 || j < 0 || i >= m || j >= n) {
         return;
     }
     //如果当前位置到达终点，对已经累加好的路径长度和最小长度比较，若小于则将其赋值给最小长度，同时将长度个数加1
     if (i == end[0] && j == end[1]) {
         if (len < minlen) {
             minlen = len;
         }
         count++;
         return;
     }
     //判断当前位置是否是障碍
     for (int c = 0; c < k; c++) {
         if (i == obstacle[c][0] && j == obstacle[c][1])
             return;
     }
     //判断当前位置是否已经访问过
    if (visited[i][j] == 1) {
        return;
    }
    //若没有访问过就进行下一个位置（向下或者向右）进行访问，并将visited[i][j]置为1，表示已经访问
     visited[i][j] = 1;
     DFS(m, n, end, obstacle, i + 1, j, k,visited, len+1, minlen, count);
     DFS(m, n, end, obstacle, i, j + 1, k,visited, len+1, minlen, count);
     //回溯将访问过的位置重新置为0，为后续新的路径做准备
     visited[i][j] = 0;
     
 }
 
 vector<int> minLength(int m,int n, vector<int>& start, vector<int>& end, int k, vector<vector<int>>& obstacle) {
     //定义len表示当前路径长度，minlen表示最小长度（初始化为最大值），count表示最短长度路径个数
     int len = 0, count = 0, minlen = INT_MAX;
     //访问标识数组
     vector<vector<int>>visited(n, vector<int>(m, 0));
     //进行深度优先遍历
     DFS(m, n, end, obstacle, start[0], start[1],2, visited,len, minlen, count);
     //将结果加入到结果数组中
     vector<int>ans;
     ans.push_back(count);
     ans.push_back(minlen);
     return ans;
 }