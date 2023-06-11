public class Playground {
    public static void main(String[] args) {
        Tree tree = new Tree();
        Node root = tree.buildTree(null);
        System.out.println(tree.verticalTraversal(root));
    }
}
//           1
//     2            3
//  4     5     6     x
// 7 8   9 x   x x
// 1 2 4 7 -1 -1 8 -1 -1 5 9 -1 -1 -1 3 6 -1 -1 -1