package main.java;

import java.util.HashMap;

public class TwoSum1 {

	/**
	 * @param args
	 */
	public int []twoSum(int[] nums, int target){

		int []aiRet = new int[2];
		HashMap<Integer, Integer> hMp = new HashMap<>();
		
		for (int i = 0; i < nums.length; i++){
			Integer n = hMp.get(nums[i]);
			if (null == n)
				hMp.put(nums[i], i);
			n = hMp.get(target - nums[i]);
			if((null != n) && (n < i)){
				aiRet[0] = n;
				aiRet[1] = i;
			}
		}
		return aiRet;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
