import java.io.*;
import java.util.*;

/**
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-03-16 04:55:00
 */
public class test {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String filename) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(filename));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object object) throws IOException {
            bw.append(String.valueOf(object));
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append('\n');
        }

        public void close() throws IOException {
            bw.close();
        }
    }

    // Debug utility methods
    static void debug(Object... args) {
        if (LOCAL) {
            System.err.println(Arrays.deepToString(args));
        }
    }
    
    static <T> void debugArray(T[] arr) {
        if (LOCAL) {
            System.err.println(Arrays.toString(arr));
        }
    }
    
    static void debugArray(int[] arr) {
        if (LOCAL) {
            System.err.println(Arrays.toString(arr));
        }
    }
    
    static void debugArray(long[] arr) {
        if (LOCAL) {
            System.err.println(Arrays.toString(arr));
        }
    }
    
    // Constants
    static final int MOD = 1_000_000_007;
    static final long INF = (long) 1e18;
    static final boolean LOCAL = System.getProperty("ONLINE_JUDGE") == null;
    static final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    // Math utilities
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    static int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    
    static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
    
    static long modPow(long base, long exp, long mod) {
        if (exp == 0) return 1;
        long half = modPow(base, exp / 2, mod);
        if (exp % 2 == 0) return (half * half) % mod;
        else return (half * half % mod) * base % mod;
    }

    // Solve method to handle each test case
    static void solve(FastReader in, FastWriter out) throws IOException {
        
    }

    public static void main(String[] args) throws IOException {
        FastReader in = new FastReader();
        FastWriter out = new FastWriter();
        
        int t = 1;
        t = in.nextInt();  // Comment this line if there is only one test case
        
        for (int tc = 1; tc <= t; tc++) {
            // Uncomment the following line if output format requires test case number
            // out.print("Case #" + tc + ": ");
            solve(in, out);
        }
        
        out.close();
    }
}
/* Trie (Prefix Tree) - For string matching and prefix operations
 * - Efficient for dictionary operations and prefix searching
 * - Time complexity: O(L) for insert/search/startsWith where L=key length
 * - Example: Insert "apple", "app", search for "app" returns true
 */
static class Trie {
    private class Node {
        Node[] children = new Node[26];
        boolean isEnd = false;
        int count = 0;  // Number of words ending here
    }
    
    private final Node root;
    
    public Trie() {
        root = new Node();
    }
    
    // Insert a word into the trie
    public void insert(String word) {
        Node curr = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) {
                curr.children[idx] = new Node();
            }
            curr = curr.children[idx];
        }
        curr.isEnd = true;
        curr.count++;
    }
    
    // Check if the trie contains a word
    public boolean search(String word) {
        Node curr = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) {
                return false;
            }
            curr = curr.children[idx];
        }
        return curr.isEnd;
    }
    
    // Check if there is any word starting with the given prefix
    public boolean startsWith(String prefix) {
        Node curr = root;
        for (char c : prefix.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) {
                return false;
            }
            curr = curr.children[idx];
        }
        return true;
    }
    
    // Count occurrences of a word
    public int countWord(String word) {
        Node curr = root;
        for (char c : word.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) {
                return 0;
            }
            curr = curr.children[idx];
        }
        return curr.isEnd ? curr.count : 0;
    }
    
    // Get all words with a given prefix
    public List<String> getWordsWithPrefix(String prefix) {
        List<String> result = new ArrayList<>();
        Node curr = root;
        
        // Reach prefix node
        for (char c : prefix.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) {
                return result;
            }
            curr = curr.children[idx];
        }
        
        // Find all words from this node
        collectWords(curr, prefix, result);
        return result;
    }
    
    private void collectWords(Node node, String prefix, List<String> result) {
        if (node.isEnd) {
            result.add(prefix);
        }
        
        for (int i = 0; i < 26; i++) {
            if (node.children[i] != null) {
                collectWords(node.children[i], prefix + (char)('a' + i), result);
            }
        }
    }
}