import java.io.File;
import java.io.IOException;

public class DirectoryTree {

    public static void createDirectoryTree(String[][][] tree, String basePath) {
        String rootDirectory = tree[0][0][0];
        File root = new File(basePath + "/" + rootDirectory);

        if (root.mkdir()) {
            System.out.println("Katalog główny utworzony: " + root.getPath());
            createDirectory(tree, root.getPath(), 1, 0);
        }
    }

    private static void createDirectory(String[][][] tree, String currentPath, int depth, int index) {
        if (depth >= tree.length || index >= tree[depth].length) {
            return;
        }

        for (int i = 0; i < tree[depth][index].length; i++) {
            String element = tree[depth][index][i];
            File file = new File(currentPath + "/" + element);

            if (element.startsWith("f")) {
                try {
                    if (file.createNewFile()) {
                        System.out.println("Plik utworzony: " + file.getPath());
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                if (file.mkdir()) {
                    System.out.println("Katalog utworzony: " + file.getPath());

                    if (depth + 1 < tree.length && i < tree[depth + 1].length) {
                        createDirectory(tree, file.getPath(), depth + 1, i);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {

        String basePath = "C:/xd";

        String[][][] tree = {
                {{"A"}},
                {{"B", "C", "D", "f1"}},
                {{"D", "f1"}, {"E"}, {}, {}}
        };

        String[][][] tree2 = {
            {{"X"}},
            {{"Y", "Z", "f1"}},
            {{"X", "f1"}, {"Z", "f1"}, {}}
        };


        createDirectoryTree(tree, basePath);
        createDirectoryTree(tree2, basePath);
    }
}



