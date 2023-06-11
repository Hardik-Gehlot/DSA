import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Tree {
    Queue<Integer> queue = new LinkedList<>();
    // private Node root = null;
    // Tree(int data){
    // root = new Node(data);
    // }
    // public Node build(){

    // }
    Tree() {
        queue.add(1);
        queue.add(2);
        queue.add(4);
        queue.add(7);
        queue.add(-1);
        queue.add(-1);
        queue.add(8);
        queue.add(-1);
        queue.add(-1);
        queue.add(5);
        queue.add(9);
        queue.add(-1);
        queue.add(-1);
        queue.add(-1);
        queue.add(3);
        queue.add(6);
        queue.add(-1);
        queue.add(-1);
        queue.add(-1);
    }

    public Node buildTree(Node root) {
        // Scanner sc = new Scanner(System.in);
        System.out.println("Enter the data: ");
        // int data = sc.nextInt();
        int data = queue.poll();
        root = new Node(data);
        if (data == -1) {
            return null;
        }
        System.out.println("Enter Data for inserting in left of " + data);
        root.left = buildTree(root);
        System.out.println("Enter Data for inserting in right of " + data);
        root.right = buildTree(root);
        return root;
    }

    public Node buildFromLevelOrderTraversal(Node root) {
        Queue<Node> q = new LinkedList<>();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter data of Root");
        int data = sc.nextInt();
        root = new Node(data);
        q.add(root);
        while (!q.isEmpty()) {
            Node temp = q.poll();
            System.out.println("Enter left node for " + temp.data);
            int leftData = sc.nextInt();
            if (leftData != -1) {
                temp.left = new Node(leftData);
                q.add(temp.left);
            }
            System.out.println("Enter right node for " + temp.data);
            int rightData = sc.nextInt();
            if (rightData != -1) {
                temp.right = new Node(rightData);
                q.add(temp.right);
            }

        }
        return root;
    }

    public void levelOrderTraversal(Node root) {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while (!q.isEmpty()) {
            Node temp = q.poll();
            if (temp == null) {
                System.out.println("");
                if (!q.isEmpty()) {
                    q.add(null);
                }
            } else {
                System.out.print(temp.data + " ");
                if (temp.left != null) {
                    q.add(temp.left);
                }
                if (temp.right != null) {
                    q.add(temp.right);
                }
            }
        }
    }

    public void inOrderTraversal(Node root) {
        if (root != null) {
            inOrderTraversal(root.left);
            System.out.print(root.data + " ");
            inOrderTraversal(root.right);
        }
    }

    public void preOrderTraversal(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preOrderTraversal(root.left);
            preOrderTraversal(root.right);
        }
    }

    public void postOrderTraversal(Node root) {
        if (root != null) {
            postOrderTraversal(root.left);
            postOrderTraversal(root.right);
            System.out.print(root.data + " ");
        }
    }

    public ArrayList<Integer> verticalTraversal(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        HashMap<Integer, HashMap<Integer, ArrayList<Integer>>> hashMap = new HashMap<>();
        Queue<HashMap.Entry<Node, HashMap.Entry<Integer, Integer>>> q = new LinkedList<>();
        q.offer(new AbstractMap.SimpleEntry<>(root, new AbstractMap.SimpleEntry<>(0, 0)));
        while (!q.isEmpty()) {
            HashMap.Entry<Node, HashMap.Entry<Integer, Integer>> curr = q.poll();
            int verticalLevel = curr.getValue().getKey();
            int horizontalLevel = curr.getValue().getValue();
            Node node = curr.getKey();
            if (!hashMap.containsKey(verticalLevel)) {
                hashMap.put(verticalLevel, new HashMap<>());
            }
            if (!hashMap.get(verticalLevel).containsKey(horizontalLevel)) {
                hashMap.get(verticalLevel).put(horizontalLevel, new ArrayList<>());
            }
            hashMap.get(verticalLevel).get(horizontalLevel).add(node.data);
            if (node.left != null) {
                q.offer(new AbstractMap.SimpleEntry<>(node.left,
                        new AbstractMap.SimpleEntry<>(verticalLevel - 1, horizontalLevel + 1)));
            }
            if (node.right != null) {
                q.offer(new AbstractMap.SimpleEntry<>(node.right,
                        new AbstractMap.SimpleEntry<>(verticalLevel + 1, horizontalLevel + 1)));
            }
        }
        ArrayList<Integer> sortedKeys = new ArrayList<>(hashMap.keySet());
        Collections.sort(sortedKeys);
        for (int key : sortedKeys) {
            for (HashMap.Entry<Integer, ArrayList<Integer>> p : hashMap.get(key).entrySet()) {
                for (Integer v : p.getValue()) {
                    ans.add(v);
                }
            }
        }
        return ans;
    }
}
