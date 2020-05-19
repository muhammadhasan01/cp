// author: donbasta
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+69;

int cnt[N];
int c[N];
int n,k,kosong;
pair<int,int> ans[N];
vector<int> ve[N], lol;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> k >> n;
	int d = k/n;
	for(int i=1; i<=k; i++){
		int x;
		cin >> x;
		if(x > 0){
			cnt[x]++;
			ve[x].push_back(i);
		}
		else{
			lol.push_back(i);
		}
	}
	kosong = (int) lol.size();

	for(int i=1; i<=n; i++){
		int temp = (cnt[i]/d) * d;
		cnt[i] %= d;
		for(int j=(int)ve[i].size()-1; j>=(int)ve[i].size()-temp; j--){
			ans[ve[i][j]] = make_pair(i,i);
		}
		for(int j=1; j<=temp; j++){
			ve[i].pop_back();
		}
	}

	int banyak = 0, rem = 0, mx = 0, idx = -1;
	for(int i=1; i<=n; i++){
		if(cnt[i] > 0)
			banyak++;
		rem += cnt[i];
		if(cnt[i] > mx){
			mx = cnt[i];
			idx = i;
		}
	}

	rem += kosong;
	// assert(rem % d == 0);
	rem /= d;
	// if(2 * rem < banyak){
	// 	cout << "No\n";
	// 	return 0;
	// }

	if(idx == -1){
		for(int i=0; i<kosong; i++){
			ans[lol[i]] = make_pair(1,1);
		}
		cout << "Yes\n";
		for(int i=1; i<=k; i++){
			cout << ans[i].first << " " << ans[i].second;
			cout << "\n";
		}
		return 0;
	} else {
		cnt[idx] += kosong;
		for(auto i : lol){
			ve[idx].push_back(i);
		}
		// priority_queue<pair<int,int>> pq;
		set<pair<int,int>> pq;
		for(int i=1; i<=n; i++){
			if(cnt[i] > 0){
				pq.insert(make_pair(cnt[i],i));
			}
		}

		while(!pq.empty()){
			if((int)pq.size()>=2){
				pair<int,int> a = *pq.rbegin(); pq.erase(a);
				pair<int,int> b = *pq.begin(); pq.erase(b);
				if(a.first + b.first < d){
					cout << "No\n";
					return 0;
				}
				int l = a.first - (d - b.first);
				int sz = (int) ve[b.second].size();
				for(int i=0; i<sz; i++){
					ans[ve[b.second][i]] = make_pair(b.second, a.second);
				}
				for(int i=1; i<=b.first; i++){
					ve[b.second].pop_back();
				}
				// assert((int)ve[b.second].size() == 0);

				sz = (int) ve[a.second].size();
				for(int i=sz-1; i>=sz-(d-b.first); i--){
					ans[ve[a.second][i]] = make_pair(a.second, b.second);
				}
				for(int i=1; i<=d-b.first; i++){
					ve[a.second].pop_back();
				}
				if(l > 0){
					pq.insert(make_pair(l, a.second));
				}
			} else {
				pair<int,int> a = *pq.begin(); pq.erase(a);
				// if (a.first % d != 0){
                //     cout << "No" << endl;
                //     return 0;
                // }
				for(int i=0; i<(int)ve[a.second].size(); i++){
					ans[ve[a.second][i]] = make_pair(a.second, a.second);
				}
			}
		}

		cout << "Yes\n";
		for(int i=1; i<=k; i++){
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
}