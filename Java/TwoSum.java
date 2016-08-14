package main.java;

public class TwoSum {

	/**
	 * @param args
	 */
	public int []twoSum(int[] nums, int target){
		int [] aiRet = new int[2];
		
		for (int i = 0; i < nums.length; i++){
			for(int j = i + 1; j < nums.length; j++){
				if((nums [i] + nums [j]) == target){
					aiRet[0] = i;
					aiRet[1] = j;
				}
			}
		}
		return aiRet;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
