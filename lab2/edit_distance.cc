#include <string>
#include <algorithm>

using namespace std;

int edit_distance(const string& p, const string& q)
{
	const maxlen = 25;

	int[maxlen+1][maxlen+1] d;

	//initsiera första raden och kolumnen enligt d(i,0)=i och d(0,j)=j
	for (int i = 0; i <= maxlen; ++i)
	{
		d[i][0] = i;
	}
	for(int j = 0; j <= maxlen ; ++j)
	{
		d[0][j] = j;
	}
	
	for(auto i = 1; i < p.size(); ++i){
		for(auto 1 = 1; j <q.size(); ++j) {
			d[i][j] = min(
				

			);

		}
	}

}
