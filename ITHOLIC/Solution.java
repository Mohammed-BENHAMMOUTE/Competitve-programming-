import java.io.*;
import java.util.*;

/**
 * Author: Mohammed BENHAMMOUTE
 * Created: 2025-03-16 12:43:07
 */
public class Solution {
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


    // Solve method to handle each test case
    static void solve(FastReader in, FastWriter out) throws IOException {
        
    }

    public static void main(String[] args) throws IOException {
        // FastReader in = new FastReader();
        // FastWriter out = new FastWriter();
        Scanner in = new Scanner(System.in) ; 
        
        int t = 1;
        t = in.nextInt(); 
        in.nextLine() ; 
        for (int tc = 1; tc <= t; tc++) {
            String s = in.nextLine()  ; 
            int n = s.length() ; 
            if( n < 3 || s.charAt(0) == '1'  ){
                System.out.println("NO") ;
            }else {
                int i=1 ; 
                while( i<n-1 && s.charAt(i) == '1' ){
                    i++ ; 
                }
                System.out.println("YES") ; 
                if( i < n-1 ){
                    System.out.println( n-1 -i ) ; 
                }else {
                    int rs = s.charAt(n-1) - '0' ; 
                    System.out.println(rs) ; 
                }
            }
            // solve(in, out);
        }
        
        // out.close();
    }
}