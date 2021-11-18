#include<iostream>
using namespace std;
int main() {
	int t; cin>>t; // itne number of scenarios aayenge
	// for(int i=1;i<=t;i++)
	while(t--)
	{

		
		int c1,c2,c3,c4; cin>>c1>>c2>>c3>>c4;
		int tot_rick,tot_cabs;
		cin>>tot_rick>>tot_cabs;
		int cost_rick=0;
		for(int j=1;j<=tot_rick;j++)
		{
			int ye_rick_kitni_baar; cin>>ye_rick_kitni_baar;
			int per_ride=c1 * ye_rick_kitni_baar;

			int ye_rick_unlimi=c2;
			cost_rick+=min(per_ride,ye_rick_unlimi);
			// if(per_ride < ye_rick_unlimi)
			// {
			// 	cost_rick+=per_ride;
			// }
			// else
			// {
			// 	cost_rick+=ye_rick_unlimi;
			// }
		}
		cost_rick=min(cost_rick, c3); // taking min with cost of using all rick
		int cost_cab=0;
		for(int i=1;i<=tot_cabs;i++)
		{
			int ye_wali_cab; cin>>ye_wali_cab;
			int per_ride=c1 * ye_wali_cab;
			cost_cab+=min(per_ride,c2);
		}

		cost_cab=min(cost_cab,c3);


		int total_cost=min(cost_rick + cost_cab,c4);
		cout<<total_cost<<endl;

	}
	return 0;
}