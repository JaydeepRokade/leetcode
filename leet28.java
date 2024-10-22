
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        List<Long> res = new ArrayList<>();  
        Queue<TreeNode> q = new LinkedList<>();  
        q.add(root);  

        while (!q.isEmpty()) {
            int n = q.size(); 
            long sum = 0;  
            
            for (int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                sum += node.val;
                
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            res.add(sum);  // Store the sum of the current level
        }

        if (k > res.size()) return -1;
        
        res.sort(Collections.reverseOrder());  // Sort level sums in descending order
        
        return res.get(k - 1);  // Return the k-th largest sum
    }
}
