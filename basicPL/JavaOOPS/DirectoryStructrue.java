import java.util.*;
// dir
// many subdir
// hold files i.e data and theere can be many of them

class DirTree{
    DirTree parent;
    String name;
    List<DirTree> children;
    String data;
    public DirTree(String s){
        this.name = s;
        this.parent = null;
        this.children = new LinkedList<DirTree>();
        this.data = "";
    }
    public void addData(String DirName, String data){

    }
    public DirTree addChildDir(String newDirName){
        DirTree childNode = new DirTree(newDirName);
        childNode.parent  = this;
        this.children.add(childNode);
        return childNode;
    }
    public void removeDir(String toBeRemDirName){

    }
}

public class DirectoryStructrue{
    public static void main(String[] args){
        // do something
    }
    
} 
