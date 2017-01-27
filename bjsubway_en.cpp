#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getString(const string& lineName, const string& terminalStationName,
	const vector<string>& stationInfo, string& res)
{
	const int stationNameFlag = 0;
	const int stationStatusFlag = 1;
	const int stationTransferFlag = 2;
	if (stationInfo[stationStatusFlag] == "terminal")
	{
		if (stationInfo[stationNameFlag] != terminalStationName)
		{
			res = res + "Welcome to take " + lineName +
			". This train will stop service at " + terminalStationName + ". ";
			return;
		}
		else
		{
			res = res + "Next station, " + stationInfo[stationNameFlag] +
				", the terminal of the train. ";
			if (stationInfo[stationTransferFlag].size() > 0)
			{
				res = res + "Interchange station for " +
					stationInfo[stationTransferFlag] + ". ";
			}
			res = res + "Please prepare to get off." +
				" Thank you for taking " + lineName + ".";
		}
	}
	else if (stationInfo[stationStatusFlag] == "closed")
	{
		return;
	}
	else
	{
		res = res + "Next station, " + stationInfo[stationNameFlag] + ".";
		if (stationInfo[stationTransferFlag].size() > 0)
		{
			res = res + " Interchange station for " +
				stationInfo[stationTransferFlag] + ".";
		}
	}
	res += "\n";
	return;
}

int main(int argc, char* argv[])
{
	vector<vector<string>> stationList = {
		{"Shangezhuang", "terminal", ""},
		{"Laiguangying", "", ""},
		{"Donghuqu", "", ""},
		{"Wangjing", "", "line 15"},
		{"Futong", "", ""},
		{"Wangjing south", "", ""},
		{"Gaojiayuan", "closed", ""},
		{"Jiangtai", "", ""},
		{"Dongfengbeiqiao", "", "line 22"},
		{"Zaoying", "", ""},
		{"Chaoyang Park", "", ""},
		{"Jintailu", "", "line 6"},
		{"Dawanglu", "", "line 1"},
		{"Jiulongshan", "", "line 7"},
		{"Pingleyuan", "closed", ""},
		{"Beigongdaximen", "", ""},
		{"Shilihe", "", "line 10"},
		{"Fangzhuang", "", ""},
		{"Puhuangyu", "", "line 5"},
		{"Jingtai", "", ""},
		{"Yongdingmenwai", "", ""},
		{"Taoranqiao", "closed", ""},
		{"Beijing south railway station",
			"terminal", "line 4, or intercity trains"}
	};
	string lineName = "Beijing MTR";
	string res = "";
	bool direction = true; // T:downward, F:upward
	if (direction)
	{
		for (vector<vector<string>>::iterator i = stationList.begin();
			i != stationList.end();
			i++)
		{
			getString(lineName, (stationList.end()-1)->at(0), *i, res);
		}
	}
	else
	{
		for (
			vector<vector<string>>::reverse_iterator i = stationList.rbegin();
			i != stationList.rend();
			i++
		)
		{
			getString(lineName, (stationList.rend()-1)->at(0), *i, res);
		}
	}
	cout<<res<<endl;
	return 0;
}
