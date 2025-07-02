import java.io.*;

class Exp12 {
    public static void main(String[] args) throws IOException {
        FileWriter fw = new FileWriter("data.txt");
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write("Hello World!\nWelcome to Java File Handling.\nLet's count lines, words, and characters.");
        bw.close();

        FileReader fr = new FileReader("data.txt");
        BufferedReader br = new BufferedReader(fr);

        int lines = 0, words = 0, characters = 0;
        String line;

        while ((line = br.readLine()) != null) {
            lines++;
            characters += line.length();
            String[] wordList = line.split("\\s+");
            words += wordList.length;
        }
        br.close();

        System.out.println("Lines: " + lines);
        System.out.println("Words: " + words);
        System.out.println("Characters: " + characters);
    }
}
