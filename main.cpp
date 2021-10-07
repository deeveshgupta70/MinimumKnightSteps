#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector<vector <T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {cerr << "\n"; for (auto i : v) { for( auto t : i){cerr<<t; cerr << " ";} cerr<<"\n";}}


bool isValid( int first , int second , int n , vector<vector<int>> &visited){
    
    if( first < 0 || first >= n ||second < 0 || second >= n || visited[first][second])
        return false;
    
    return true;
}

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
{
    // Code here
    
    vector<vector<int>> visited( n , vector<int>( n , 0));
    
    int s1 = KnightPos[0]-1;
    int s2 = KnightPos[1]-1;
    
    int d1 = TargetPos[0]-1;
    int d2 = TargetPos[1]-1;
    
    if( s1 == d1 && s2 == d2) return 0;
    
    queue<pair<int,int>> q;
    q.push({s1,s2});
    
    while( !q.empty()){
        
        pair<int,int> temp = q.front();
        q.pop();
        
        if( isValid( temp.first + 2, temp.second+1 , n , visited))
        {
            visited[temp.first + 2][ temp.second+1] = visited[temp.first][temp.second] + 1;
            q.push({temp.first + 2, temp.second+1});
        }
            
        if( isValid( temp.first + 2, temp.second-1 , n , visited)){
            visited[temp.first + 2][temp.second - 1] = visited[temp.first][temp.second] + 1;
            q.push({temp.first + 2, temp.second-1});
        }
        
        if( isValid( temp.first - 2, temp.second+1 , n , visited)){
            visited[temp.first - 2][temp.second + 1] = visited[temp.first][temp.second] + 1;
            q.push({temp.first - 2, temp.second+1});
        }
        
        if( isValid( temp.first - 2, temp.second-1 , n , visited)){
            visited[temp.first - 2][temp.second - 1] = visited[temp.first][temp.second] + 1;
            q.push({temp.first - 2, temp.second-1});
        }
        
        if( isValid( temp.first + 1, temp.second+2 , n , visited)){
            visited[temp.first + 1][temp.second + 2] = visited[temp.first][temp.second] + 1;
            q.push({temp.first + 1, temp.second+2});
        }
        
        if( isValid( temp.first - 1, temp.second+2 , n , visited)){
            visited[temp.first - 1][temp.second + 2] = visited[temp.first][temp.second] + 1;	            
            q.push({temp.first - 1, temp.second+2});
         }
         
        if( isValid( temp.first - 1, temp.second-2 , n , visited)){
            visited[temp.first - 1][temp.second - 2] = visited[temp.first][temp.second] + 1;
            q.push({temp.first - 1, temp.second-2});
        }    
            
        if( isValid( temp.first +1, temp.second-2 , n , visited)){
            visited[temp.first + 1][temp.second - 2] = visited[temp.first][temp.second] + 1;	            
            q.push({temp.first + 1, temp.second-2});
        }
        
    }
    
    return visited[d1][d2];
    
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();
 
 int n;
 cin>>n;
 vector<int> knightPos(2),TargetPos(2);

 cin>>knightPos[0]>>knightPos[1]>>TargetPos[0]>>TargetPos[1];

 int res = minStepToReachTarget(knightPos , TargetPos , n);
 cout<<"\nMinimum Knight Steps : "<<res;

return 0;

}
/*
Input:
6
4 5
1 1

Ouput:

Minimum Knight Steps : 3
*/
