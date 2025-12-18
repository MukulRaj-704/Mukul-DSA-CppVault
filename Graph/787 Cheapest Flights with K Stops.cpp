 queue<pair<int,pair<int,int>>>q;
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int a,b,w;
            a=it[0];
            b=it[1];
            w=it[2];
            adj[a].push_back({b,w});
        }
        q.push({0,{src,0}});
        vector<int>disst(n,1e9);
        disst[src]=0;
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();
            if(stop>K) continue;
            for(auto it: adj[node]){
                int vt=it.first;
                int wt=it.second;
                if(dist+wt<disst[vt] && stop<=K){
                    disst[vt]=dist+wt;
                    q.push({stop+1,{vt,disst[vt]}});
                }
                
            }
        }
        if(disst[dst]==1e9) return -1;
        return disst[dst];
