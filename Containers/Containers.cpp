#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

unsigned int GetHash(std::string str)
{
	unsigned int hash = 0;
	for (char c : str)
	{
		hash = hash * 31 + (int)c;
	}

	return hash;
}


int main()
{
	// array
	array<int, 5> arr = { 1, 2, 3, 4, 5 };
	cout << arr.size() << endl;

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}

	// vector
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vec.push_back(6);
	vec[0] = 5;

	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
	s.push(5);
	cout << s.top() << endl;

	// list
	list<int> lst = { 1, 2, 3, 4, 5 };
	lst.push_back(6);
	lst.insert(lst.begin(), 0);

	// iterator
	for (auto iter = lst.begin(); iter != lst.end(); iter++)
	{
		cout << *iter << endl;
	}

	// map (ordered map)
	map<string, int> m;
	m["riley"] = 46;
	m["garrett"] = 86;
	m["mike"] = 100;

	cout << m["riley"] << endl;
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}

	// unordered map
	unordered_map<int, string> um;
	um[1245] = "allmendinger";
	um[7457] = "oxborrow";
	cout << um[1245] << endl;


	string name = "Raymond";
	int hash = GetHash(name);
	cout << hash << endl;

	int data[10];
	data[hash % 10] = 84025;

	// bunch of stuff
	hash = GetHash("Raymond");
	cout << data[hash % 10] << endl;

	return 0;
}

