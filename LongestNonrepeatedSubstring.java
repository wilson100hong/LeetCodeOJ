
public class LongestNonrepeatedSubstring {
	
	public int lengthOfLongestSubstring(String s) {
		int MAX_N = 1000;
		boolean eat[] = new boolean[MAX_N];
		for (int i = 0; i < MAX_N; ++i)
			eat[i] = false;
		
		char[] array = s.toCharArray();
		int max = 0;
		int left = 0, right = 0;
		while (right < array.length) {
			char c = array[right];
			while (eat[c] && left <= right) {
				eat[array[left]] = false;
				left++;
			}
			eat[c] = true;
			int len = right - left + 1;
			if (len > max)
				max = len;
			right++;
		}
		return max;
	}
	
	
	public static void main(String[] args) {
		LongestNonrepeatedSubstring sol = new LongestNonrepeatedSubstring();
		System.out.println(sol.lengthOfLongestSubstring("abcabcbb"));
		System.out.println(sol.lengthOfLongestSubstring("bbbbb"));
	}

}
