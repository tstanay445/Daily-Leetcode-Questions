class Solution {
public:
    static bool mycmp(pair<int,int>& p1,pair<int,int>& p2){
        return p1.second < p2.second;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& v, int firstPerson) {
        unordered_set<int> knows;
        knows.insert(0);
        knows.insert(firstPerson);
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0;i<v.size();i++){
            adj[v[i][0]].push_back({v[i][1],v[i][2]});
            adj[v[i][1]].push_back({ v[i][0], v[i][2]});
        }
        for(int i = 0;i<n;i++){
            sort(adj[i].begin(),adj[i].end(),mycmp);
        }
        vector<int> best(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({0,0});
        q.push({firstPerson,0});
        best[0] = 0;
        best[firstPerson] = 0;
        while(q.size()){
            auto top = q.front();
            q.pop();
            int node= top.first;
            int time = top.second;
            // cout<<node<<endl;
            for(int i = 0;i<adj[node].size();i++){
                if(time <= adj[node][i].second && best[adj[node][i].first] > adj[node][i].second){
                    best[adj[node][i].first] = adj[node][i].second;
                    q.push({adj[node][i].first,adj[node][i].second});
                    knows.insert(adj[node][i].first);
                }
            }
        }
        vector<int> x(knows.begin(),knows.end());
        return x;
    }
};