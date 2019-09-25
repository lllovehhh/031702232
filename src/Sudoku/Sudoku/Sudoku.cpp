#include <bits/stdc++.h>
using namespace std;
int sd[11][11], m, sudoku[100000] = { 0 }, k = 1, n, t;//数独数组，n宫格 
bool p[11][11], l[11][11], fz[11][11];//排，列，方阵。 
void out()
{

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sudoku[k++] = sd[i][j];
		}

	}

	//	memset(sd, 0, sizeof(sd));



	   //exit(0);
}
void dfsm(int x, int y)
{
	;
	if (sd[x][y] != 0)//如果原来这个位置有数字，跳过。 
		if (x == m && y == m) out();
		else if (y == m)dfsm(x + 1, 1);
		else dfsm(x, y + 1);
	else//原来的地方没有数字，准备填充 
		for (int i = 1; i <= m; i++)
			if ((!p[x][i]) && (!l[y][i]))
			{
				sd[x][y] = i;
				p[x][i] = l[y][i] = true;
				if (x == m && y == m) out();
				else if (y == m)dfsm(x + 1, 1);
				else dfsm(x, y + 1);
				sd[x][y] = 0;
				p[x][i] = l[y][i] = false;
			}
}
void dfs4(int x, int y)
{
	if (sd[x][y] != 0)
		if (x == 4 && y == 4) out();
		else if (y == 4)dfs4(x + 1, 1);
		else dfs4(x, y + 1);
	else
		for (int i = 1; i <= 4; i++)
			if ((!p[x][i]) && (!l[y][i]) && (!fz[(x - 1) / 2 * 2 + (y - 1) / 2 + 1][i]))
			{
				sd[x][y] = i;
				p[x][i] = l[y][i] = fz[(x - 1) / 4 * 4 + (y - 1) / 2 + 1][i] = true;
				if (x == 4 && y == 4) out();
				else if (y == 4)dfs4(x + 1, 1);
				else dfs4(x, y + 1);
				sd[x][y] = 0;
				p[x][i] = l[y][i] = fz[(x - 1) / 2 * 2 + (y - 1) / 2 + 1][i] = false;
			}
}
void dfs6(int x, int y)
{
	if (sd[x][y] != 0)
		if (x == 6 && y == 6) out();
		else if (y == 6)dfs6(x + 1, 1);
		else dfs6(x, y + 1);
	else
		for (int i = 1; i <= 6; i++)
			if ((!p[x][i]) && (!l[y][i]) && (!fz[(x - 1) / 2 * 2 + (y - 1) / 3 + 1][i]))
			{
				sd[x][y] = i;
				p[x][i] = l[y][i] = fz[(x - 1) / 2 * 2 + (y - 1) / 3 + 1][i] = true;
				if (x == 6 && y == 6) out();
				else if (y == 6)dfs6(x + 1, 1);
				else dfs6(x, y + 1);
				sd[x][y] = 0;
				p[x][i] = l[y][i] = fz[(x - 1) / 2 * 2 + (y - 1) / 3 + 1][i] = false;
			}
}
void dfs8(int x, int y)
{
	if (sd[x][y] != 0)
		if (x == 8 && y == 8) out();
		else if (y == 8)dfs8(x + 1, 1);
		else dfs8(x, y + 1);
	else
		for (int i = 1; i <= 8; i++)
			if ((!p[x][i]) && (!l[y][i]) && (!fz[(x - 1) / 4 * 4 + (y - 1) / 2 + 1][i]))
			{
				sd[x][y] = i;
				p[x][i] = l[y][i] = fz[(x - 1) / 4 * 4 + (y - 1) / 2 + 1][i] = true;
				if (x == 8 && y == 8) out();
				else if (y == 8)dfs8(x + 1, 1);
				else dfs8(x, y + 1);
				sd[x][y] = 0;
				p[x][i] = l[y][i] = fz[(x - 1) / 4 * 4 + (y - 1) / 2 + 1][i] = false;
			}
}
void dfs9(int x, int y)
{
	if (sd[x][y] != 0)
		if (x == 9 && y == 9) out();
		else if (y == 9)dfs9(x + 1, 1);
		else dfs9(x, y + 1);
	else
		for (int i = 1; i <= 9; i++)
			if ((!p[x][i]) && (!l[y][i]) && (!fz[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i]))

			{
				sd[x][y] = i;
				p[x][i] = l[y][i] = fz[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = true;
				if (x == 9 && y == 9) out();
				else if (y == 9)dfs9(x + 1, 1);
				else dfs9(x, y + 1);
				sd[x][y] = 0;
				p[x][i] = l[y][i] = fz[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = false;
			}
}
int main(int argc, char** argv)
{

	ifstream infile;
	ofstream outfile;
	if (argc == 1)
	{
		m = 3, n = 1;
		outfile.open("g:\\软工实践\\output.txt");
		infile.open("g:\\软工实践\\input.txt");
	}
	else
	{
		m = atoi(argv[2]);
		n = atoi(argv[4]);
		outfile.open("g:\\软工实践\\output.txt");
		infile.open("g:\\软工实践\\input.txt");
	}
	while (n--)
	{

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= m; j++)
			{

				char c;
				infile >> c;
				int t;
				t = c - 48;
				if (t != 0)
				{
					if (m == 3 || m == 5 || m == 7) p[i][t] = l[j][t] = fz[i][j] = true;
					if (m == 4) p[i][t] = l[j][t] = fz[(i - 1) / 2 * 2 + (j - 1) / 2 + 1][t] = true;
					if (m == 6) p[i][t] = l[j][t] = fz[(i - 1) / 2 * 2 + (j - 1) / 3 + 1][t] = true;
					if (m == 8) p[i][t] = l[j][t] = fz[(i - 1) / 4 * 4 + (j - 1) / 2 + 1][t] = true;
					if (m == 9) p[i][t] = l[j][t] = fz[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][t] = true;
				}

				sd[i][j] = t;
			}
		if (m == 3 || m == 5 || m == 7) dfsm(1, 1);
		if (m == 4) dfs4(1, 1);
		if (m == 6) dfs6(1, 1);
		if (m == 8) dfs8(1, 1);
		if (m == 9) dfs9(1, 1);
		memset(p, 0, sizeof(p));
		memset(l, 0, sizeof(l));
		memset(fz, 0, sizeof(fz));
	}

	//cout<<"k="<<k<<endl;outfile <<"k="<<k<<endl
	for (int i = 1; i < k; i++)
	{
		cout << sudoku[i] << " "; outfile << sudoku[i] << " ";
		if (i%m == 0)
		{
			cout << endl; outfile << endl;
			//cout<<"i="<<i<<endl;outfile <<"i="<<i<<endl
			if (i % (m*m) == 0)
			{
				cout << endl; outfile << endl;
			}
		}

	}

	return 0;
}