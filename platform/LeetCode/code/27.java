// 94. https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        TreeNode currentNode = root;
        List<Integer> outList = new ArrayList<Integer>();
        Stack<TreeNode> treeStack = new Stack<TreeNode>();
        while(true) {
            while(currentNode != null) {
                treeStack.push(currentNode);
                currentNode = currentNode.left;
            }
            if(treeStack.isEmpty()) {
                return outList;
            }
            currentNode = treeStack.pop();
            outList.add(currentNode.val);
            currentNode = currentNode.right;
        }
    }
}