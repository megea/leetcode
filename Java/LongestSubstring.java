package main.java;

public class LongestSubstring {

	/**
	 * @param args
	 * 
	 * Given a string, find the length of the longest substring without repeating characters.
	 * Examples:
	 * Given "abcabcbb", the answer is "abc", which the length is 3.
	 * Given "bbbbb", the answer is "b", with the length of 1.
	 * Given "pwwkew", the answer is "wke", with the length of 3. 
	 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
	 * Subscribe to see which companies asked this question
	 * 
	 */
	public static int lengthOfLongestSubstring(String s){
		
		if (s == null){
			return 0;
		}
		int lengthTemp = 0;
		char[] ch = s.toCharArray();
		int [] sumOfChar = new int[256];
		int lengthMax = 0;
		int [] temp = new int[256];	//字符串中每个字符的绝对位置
		int iRepPoint = 0;
		
		for (int i = 0; i < ch.length; i++){
			if (sumOfChar[ch[i]] < 1){
				lengthTemp = i - iRepPoint;
				temp [ch[i]] = i;
			}
			if (sumOfChar[ch[i]] >= 1){
				lengthTemp = i - temp[ch[i]];
				temp[ch[i]] = i;
				iRepPoint = i;
			}
			lengthMax = (lengthMax > lengthTemp ? lengthMax : lengthTemp);
			sumOfChar[ch[i]]++;
		}
		return lengthMax;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		char[] s = "helloworld!".toCharArray();
//		int[] temp = new int [256];
//		for (int i = 0; i < s.length; i ++){
//			temp [s[i]]++;
//		}
//		int i = 0;
//		while (temp[s[i]] != 0){
//			System.out.println(temp[s[i]]);
//			i ++;
//		}
		String s = "helloworld!";
		System.out.println(lengthOfLongestSubstring(s));
	}

} 
