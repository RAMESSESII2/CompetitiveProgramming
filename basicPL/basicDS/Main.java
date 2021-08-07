import java.io.*;
//root, leftSubchild, rightSubchild

class BinarySearchTree{
    Node root;
    class Node{
        public int data;
        public Node left;
        public Node right;
        Node(int d){
            data = d;
            left = null;
            right = null;
        }
    }
    BinarySearchTree(){
        root = null;
    }

    boolean searchTree(Node r, int val){
        if( r == null ) return false;
        if( r.data == val) return true;
        if( r.data > val ) return searchTree(r.left, val);
        else return searchTree(r.right, val);
    }
    void insertValue(int val){ root = insertValue(root, val); }
    Node insertValue(Node r, int val){
        if( r == null ){
            r = new Node(val);
        }
        else{
            if( r.data > val ){
                return r.left = insertValue(r.left, val);
            }
            else return r.right = insertValue(r.right, val);
        }
        return r;
    }
}

public class Main{
    public static void main(String[] args){
        BinarySearchTree BST = new BinarySearchTree();
        BST.insertValue(3);
    }
}
