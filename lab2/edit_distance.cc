#include <string>
#include <algorithm>

using namespace std;

int edit_distance(const string& p, const string& q)
{
	const size_t qlen = q.size();
	const size_t plen = p.size();
	const int maxlen = 25;

	int d[maxlen+1][maxlen+1];

	//initsiera första raden och kolumnen enligt d(i,0)=i och d(0,j)=j
	for (size_t i = 0; i <= plen; ++i)
	{
		d[i][0] = i;
	}
	for(size_t j = 0; j <= qlen ; ++j)
	{
		d[0][j] = j;
	}
	
	for(size_t i = 1; i <= plen; ++i){
		for(size_t j = 1; j <= qlen; ++j) {
			if(q[j-1] == p[i-1]){
				d[i][j] = d[i-1][j-1];
			}else{
				d[i][j] = min({d[i-1][j], d[i-1][j-1], d[i][j-1]}) + 1;
			}
		}
	}

	int res  = d[p.size()][q.size()];
	return res;
}
