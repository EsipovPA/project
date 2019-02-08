#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include<utility>
#include<tuple>
using namespace std;

template<typename T> T Sqr(T x);

template<typename T>
vector<T> operator * (const vector<T>& v1,const  vector<T> v2){
	vector<T> v3={};
	for (unsigned int i=0;i<v1.size();i++){
		T	t=v1[i]*v2[i];
		v3.push_back(t);
	}
	return v3;

}


template<typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2){
	First f = p1.first * p2.first;
	Second t = p1.second * p2.second;
	//return make_pair(f,t);
	return {f, t};
}

template<typename Key, typename Value>
map<Key,Value> operator * ( const map<Key,Value>& m1, const map<Key,Value> m2) {
	map<Key,Value> m3;
	for (auto i:m1){
		Value	v=i.second*i.second;
	//	Value v = Sqr(i.second);
		Key k = i.first;
		m3[k]=v;
	}

	return m3;
}


template<typename T>
 T Sqr(T x){
	return x * x;
}


int main() {
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

  return 0;
}
