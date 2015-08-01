int cost[MAX_V][MAX_V]; //assume cost[u][v]>0
int d[MAX_V];
bool used[MAX_V];
void Dijkstra(int s, int t, int V){
    for(int i=1; i<=V; i++)
        used[i]=false, d[i]=INT_MAX, pre[i]=0;
    d[s]=0;
    while(true){
        int u=-1;
        for(int v=1; v<=V; v++){
            if(!used[v]&&(u==-1||d[v]<d[u])) u=v;
        }
        if(u==-1||u==t) break;
        used[u]=true;
        for(int v=1; v<=V; v++){
            if(!cost[u][v]||used[v]) continue;
            if(d[v]>d[u]+cost[u][v])
                d[v]=d[u]+cost[u][v], pre[v]=u;
        }
    }    
}
