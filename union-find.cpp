/*
	2014年8月22日 13:22:56
	并查集
*/

#define N 100

int map[N];

void init(int from, int n)
{
	for( ; from < n; ++from)
	{
		map[from] = from;
	}
}

int Find(int a)
{
	if(a==map[a])	
		return a;
	map[a] = Find(map[a]);	//路径压缩
	return map[a];
}

void Union(int a, int b)
{
	int i = find(a);
	int j = find(b);
	if(i!=j)
		map[i] = j;
}


