using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;


public class MayTheBestPetWin
{
	public int calc(int[] A, int[] B)
	{
		int s1 = 0;
		int s2 = 0;
		
		int n = A.Length;
		for (int i = 0;i < n;i++)
		{
			s1 += A[i]; s2 += B[i];
		}
		
		bool []D = new bool[s1 + s2 + 1];
		D[0] = true;
		for (int i = 0;i < n;i++)
		{
			//for (int s = 0;s <= s1 + s2 - (A[i] + B[i]);s++)
			for (int s = s1 + s2 - (A[i] + B[i]);s >= 0;s--)
				if (D[s])
				{
					Console.Write(" {0}", A[i] + B[i]);
					D[s + A[i] + B[i]] = true;
				}
			Console.Write(": ");
			for (int j = 0;j < D.Length;j++)
				Console.Write("{0} ", D[j] ? 1 : 0);
			Console.WriteLine();
		}
		
		int min = int.MaxValue;
		for (int s = 0;s <= s1 + s2;s++)
			if (D[s])
				min = Math.Min(min, Math.Max(Math.Abs(s - s2), Math.Abs(s1 - s)));
		return min;
	}

	// BEGIN KAWIGIEDIT TESTING
	// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
	#region Testing code generated by KawigiEdit
	[STAThread]
	private static Boolean KawigiEdit_RunTest(int testNum, int[] p0, int[] p1, Boolean hasAnswer, int p2) {
		Console.Write("Test " + testNum + ": [" + "{");
		for (int i = 0; p0.Length > i; ++i) {
			if (i > 0) {
				Console.Write(",");
			}
			Console.Write(p0[i]);
		}
		Console.Write("}" + "," + "{");
		for (int i = 0; p1.Length > i; ++i) {
			if (i > 0) {
				Console.Write(",");
			}
			Console.Write(p1[i]);
		}
		Console.Write("}");
		Console.WriteLine("]");
		MayTheBestPetWin obj;
		int answer;
		obj = new MayTheBestPetWin();
		DateTime startTime = DateTime.Now;
		answer = obj.calc(p0, p1);
		DateTime endTime = DateTime.Now;
		Boolean res;
		res = true;
		Console.WriteLine("Time: " + (endTime - startTime).TotalSeconds + " seconds");
		if (hasAnswer) {
			Console.WriteLine("Desired answer:");
			Console.WriteLine("\t" + p2);
		}
		Console.WriteLine("Your answer:");
		Console.WriteLine("\t" + answer);
		if (hasAnswer) {
			res = answer == p2;
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
		
		int[] p0;
		int[] p1;
		int p2;
		
		// ----- test 0 -----
		p0 = new int[]{3,4,4,7};
		p1 = new int[]{3,4,4,7};
		p2 = 2;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 1 -----
		p0 = new int[]{1,3,5,4,5};
		p1 = new int[]{2,5,6,8,7};
		p2 = 5;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
		
		// ----- test 2 -----
		p0 = new int[]{2907,949,1674,6092,8608,5186,2630,970,1050,2415,1923,2697,5571,6941,8065,4710,716,756,5185,1341,993,5092,248,1895,4223,1783,3844,3531,2431,1755,2837,4015};
		p1 = new int[]{7296,6954,4407,9724,8645,8065,9323,8433,1352,9618,6487,7309,9297,8999,9960,5653,4721,7623,6017,7320,3513,6642,6359,3145,7233,5077,6457,3605,2911,4679,5381,6574};
		p2 = 52873;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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