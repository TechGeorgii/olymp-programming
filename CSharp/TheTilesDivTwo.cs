using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;


public class TheTilesDivTwo
{
	int n, m;

	public int find(string[] b)
	{
		n = b.Length;
		m = b[0].Length;
		
		if (m == 1 || n == 1) return 0;
		
		int [,]D = new int[1 << (2*n), m];
		
		for (int p = 1;p < m;p++)
		{			
			for (int g = 0;g < 4;g++)
			{
				bool[,] gg = gen(j)
				for (int i = 0;i < n - 1;i++)
				{
					ok = true;
					for (int x = 0;x < 2;x++)
						for (int y = 0;y < 2;y++)
							if (b[p-1 + x, i + y] == 'X' && gg[x, y])
							{
								ok = false;
							}
					if (ok)
					{
						int cx, cy;
						cx = cy = 0;
						if (g == 0)
						{
							cx = cy = 1;
						}
						if (g == 1)
						{
							cx = 1;
							cy = 0;
						}
						if (g == 2)
						{
							cx = 0;
							cy = 1;
						}
						if (g == 3)
						{
							cx = cy = 0;
						}
						
						ok = (p-1 + cx  +   i + cy) % 2 == 0;
					}
					
					if (ok)
					{
						
					}
				}
			}
		}		
	}
	
	bool[,] field(int mask)
	{
		if (mask >= (1<<(n*2))) throw new Exception();
		
		bool[,] r = new bool[n, 2];
		for (int i = 0, k = 0;i < n;i++)
			for (int j = 0;j < 2;j++, k++)
			{
				r[i, j] = ((mask >> k)&1) == 1;
			}
		return r;
	}
	
	bool[,] gen(int num)
	{
		bool [,]r = new bool[2, 2];
		int k = 0;
		for (int i = 0;i < 2;i++)
			for (int j = 0;j < 2;j++, k++)
			{
				r[i, j] = k == num ? false : true;
			}
		return r;
	}

	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	#region Testing code generated by KawigiEdit
	[STAThread]
	private static Boolean KawigiEdit_RunTest(int testNum, string[] p0, Boolean hasAnswer, int p1) {
		Console.Write("Test " + testNum + ": [" + "{");
		for (int i = 0; p0.Length > i; ++i) {
			if (i > 0) {
				Console.Write(",");
			}
			Console.Write("\"" + p0[i] + "\"");
		}
		Console.Write("}");
		Console.WriteLine("]");
		TheTilesDivTwo obj;
		int answer;
		obj = new TheTilesDivTwo();
		DateTime startTime = DateTime.Now;
		answer = obj.find(p0);
		DateTime endTime = DateTime.Now;
		Boolean res;
		res = true;
		Console.WriteLine("Time: " + (endTime - startTime).TotalSeconds + " seconds");
		if (hasAnswer) {
			Console.WriteLine("Desired answer:");
			Console.WriteLine("\t" + p1);
		}
		Console.WriteLine("Your answer:");
		Console.WriteLine("\t" + answer);
		if (hasAnswer) {
			res = answer == p1;
		}
		if (!res) {
			Console.WriteLine("DOESN'T MATCH!!!!");
		} else if ((endTime - startTime).TotalSeconds >= 2) {
			Console.WriteLine("FAIL the timeout");
			res = false;
		} else if (hasAnswer) {
			Console.WriteLine("Match :-)");
		} else {
			Console.WriteLine("OK, but is it right?");
		}
		Console.WriteLine("");
		return res;
	}
	public static void Main(string[] args) {
		Boolean all_right;
		all_right = true;
		
		string[] p0;
		int p1;
		
		// ----- test 0 -----
		p0 = new string[]{"X.X","...","X.X"};
		p1 = 1;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = new string[]{"...","...","..."};
		p1 = 2;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = new string[]{"......X.X.XXX.X.XX."};
		p1 = 0;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
		
		// ----- test 3 -----
		p0 = new string[]{"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX","....XX....X.XX..X.X...XX.X..XXXXXXX..X","XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."};
		p1 = 13;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
		
		if (all_right) {
			Console.WriteLine("You're a stud (at least on the example cases)!");
		} else {
			Console.WriteLine("Some of the test cases had errors.");
		}
	}
	#endregion
	// END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
