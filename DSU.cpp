int par[MAXN], sz[MAXN];

void reset(){
    for(int i = 0; i < MAXN; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    while(x != par[x])
        x = par[x];
    return x;
}

bool same(int x, int y){
    return find(x) == find(y);
}

int unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y){
        return 0;
    }
    if(sz[x] < sz[y])
        swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
    return 1;
}