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
	if (stationInfo[stationStatusFlag] == "终点站")
	{
		if (stationInfo[stationNameFlag] != terminalStationName)
		{
			res = res + "欢迎乘坐" + lineName + "列车，本次列车开往" +
				terminalStationName + "及沿途各站。";
			return;
		}
		else
		{
			res = res + "下一站，" + stationInfo[stationNameFlag] +
				"，本次列车的终点站。";
			if (stationInfo[stationTransferFlag].size() > 0)
			{
				res = res + "乘客可换乘" + stationInfo[stationTransferFlag] +
					"。";
			}
			res = res + "请所有乘客带好您的物品，按顺序下车。" +
				"感谢您乘坐" + lineName + "列车。";
		}
	}
	else if (stationInfo[stationStatusFlag] == "封闭")
	{
		return;
	}
	else
	{
		res = res + "下一站，" + stationInfo[stationNameFlag] + "。";
		if (stationInfo[stationTransferFlag].size() > 0)
		{
			res = res + "乘客可换乘" + stationInfo[stationTransferFlag] +
				"。";
		}
	}
	res += "\n";
	return;
}

int main(int argc, char* argv[])
{
	vector<vector<string>> stationList = {
		{"善各庄", "终点站", ""},
		{"来广营", "", ""},
		{"东湖渠", "", ""},
		{"望京", "", "地铁十五号线"},
		{"阜通", "", ""},
		{"望京南", "", ""},
		{"高家园", "封闭", ""},
		{"将台", "", ""},
		{"东风北桥", "", "地铁二十二号线"},
		{"枣营", "", ""},
		{"朝阳公园", "", ""},
		{"金台路", "", "地铁六号线"},
		{"大望路", "", "地铁一号线"},
		{"九龙山", "", "地铁七号线"},
		{"平乐园", "封闭", ""},
		{"北工大西门", "", ""},
		{"十里河", "", "地铁十号线"},
		{"方庄", "", ""},
		{"蒲黄榆", "", "地铁五号线"},
		{"景泰", "", ""},
		{"永定门外", "", ""},
		{"陶然桥", "封闭", ""},
		{"北京南站", "终点站", "地铁四号线，或至北京火车南站"}
	};
	string lineName = "京港地铁十四号线";
	string res = "";
	bool direction = true; // T:下行, F:上行
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
