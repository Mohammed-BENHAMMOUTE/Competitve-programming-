    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    	int t;
    	cin>>t;
    	while(t--){
    		int n,m,k,a[200005],b[200005],now=0,ans=0;
    		cin>>n>>m>>k;
    		for(int i=1;i<=n;i++) cin>>a[i];
    	    map<int,int> mp;
    		for(int i=1;i<=m;i++) cin>>b[i],mp[b[i]]++;
    		for(int i=1;i<=n;i++){
    			if(--mp[a[i]]<0){
    				now++;
    			}
    			if(i>=m){
    				if(m-k>=now) ans++;
    				int c=a[i-m+1];
    				if(mp[c]++<0){
    					now--;
    				}
    			}
    		}
    		cout<<ans<<'\n';
    	}
    	return 0;
    }