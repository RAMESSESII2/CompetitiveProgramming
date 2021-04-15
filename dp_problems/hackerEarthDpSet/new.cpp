    #include <bits/stdc++.h>
    #define M 1000000007
    using namespace std;
    int main() {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int T;
        cin>>T;
        while(T--)
        {
            string str;
            cin>>str;
            int N=str.size();
            int count1[N][10],count2[N][10];
            for(int i=0;i<N;i++)
                for(int j=0;j<10;j++)
                    count1[i][j]=count2[i][j]=0;
            for(int i=0;i<N;i++)
            {
                if(i!=0)
                    for(int j=0;j<10;j++)
                        count1[i][j]+=count1[i-1][j];
                count1[i][str[i]-'0']++;
            }
            for(int i=N-1;i>=0;i--)
            {
                if(i!=N-1)
                    for(int j=0;j<10;j++)
                        count2[i][j]+=count2[i+1][j];
                count2[i][str[i]-'0']++;        
            }
        
            long long ans=0;
            for(int i=1;i<N-1;i++)
            {
                if(str[i]=='9')
                    continue;
                long long c1=count1[i-1][str[i]-'0'];
                long long c2=count2[i+1][str[i]-'0'+1];
                if(c2==0)
                    continue;
                ans=(ans+(c1*((c2*(c2-1)/2)%M))%M)%M;
            }
            cout<<ans<<endl;
        
        }
    }
