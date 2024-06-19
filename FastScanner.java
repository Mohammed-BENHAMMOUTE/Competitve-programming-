import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
public class FastScanner {
    private BufferedReader br;
    private StringTokenizer st;

    public FastScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer("");
    }

    private String next() {
        while (!st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String str = "";
        try {
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }

    public char nextChar() {
        return next().charAt(0);
    }

    public boolean nextBoolean() {
        return Boolean.parseBoolean(next());
    }

    public int[] nextIntArray(int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = nextInt();
        }
        return array;
    }

    public long[] nextLongArray(int n) {
        long[] array = new long[n];
        for (int i = 0; i < n; i++) {
            array[i] = nextLong();
        }
        return array;
    }

    public double[] nextDoubleArray(int n) {
        double[] array = new double[n];
        for (int i = 0; i < n; i++) {
            array[i] = nextDouble();
        }
        return array;
    }

    public String[] nextStringArray(int n) {
        String[] array = new String[n];
        for (int i = 0; i < n; i++) {
            array[i] = next();
        }
        return array;
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int n,k;
        n = sc.nextInt(); k = sc.nextInt();
        int[] arr = new int[n+1];
        for(int i =1; i <= n; i++)
        {
           arr[i] = 0;
        };
        for(int i = 1; i <= k; i++)
        {
            int a, b;
            a = sc.nextInt(); b = sc.nextInt();
            for(int j = a; j <= b; j++)
            {
                arr[j]++;
            };
        };
        Arrays.sort(arr);
        int median = arr[(n+1)/2];
        System.out.println(median);
    }
}