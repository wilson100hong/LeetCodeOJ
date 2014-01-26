import java.util.ArrayList;
import java.util.List;


public class UniqBST2 {

	// Definition for binary tree
	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
			left = null;
			right = null;
		}
	}

	public ArrayList<TreeNode> recGenTrees(List<Integer> nums) {
		ArrayList<TreeNode> result = new ArrayList<TreeNode>();
		if (nums.size() == 0) {
			result.add(null);
			return result;
		}
		
		
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			ArrayList<TreeNode> leftTree = recGenTrees(nums.subList(0, i));
			ArrayList<TreeNode> rightTree= recGenTrees(nums.subList(Math.min(i + 1, n), n));
			for (TreeNode ltn : leftTree) {
				for (TreeNode rtn : rightTree) {
					TreeNode root = new TreeNode(nums.get(i));
					root.left = ltn;
					root.right = rtn;
					result.add(root);
				}
				
			}
			
		}
		return result;
	}
	
	
	public ArrayList<TreeNode> generateTrees(int n) {
		List<Integer> nums = new ArrayList<Integer>();
		for (int i = 0; i < n; ++i)
			nums.add(i + 1);
		return recGenTrees(nums);
	}	
	
	public void dump(TreeNode n) {
		if (n != null) {
			System.out.print(n.val);
			dump(n.left);
			dump(n.right);
		}
	}
	
	public void dumpAll(ArrayList<TreeNode> tn) {
		for (TreeNode n : tn) {
			dump(n);
			System.out.println("");
		}
	}
	
	public static void main(String[] args) {
		UniqBST2 sol = new UniqBST2();
		sol.dumpAll(sol.generateTrees(1));
	}

}
