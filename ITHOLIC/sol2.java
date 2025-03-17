import java.util.* ;
public class sol2 {
    public static boolean isChar( char c ){
        return ( c>='a' && c<='z' ) || ( c >= 'A' && c <= 'Z' ) ; 
    }
    public static void main(String[] args) {
        Scanner sc =  new Scanner( System.in ) ; 
        String s = sc.nextLine() ; 
        int n = s.length() ; 
        char[] chars = s.toCharArray() ; 
        int curr = s.split(" ").length  ; 
        for( int i=0 ; i<n ; ++i ){
            if( isChar( chars[i] ) ){
                if( chars[i] >= 'a' ){
                    int in = s.charAt(i) - 'a' ; 
                    long off = (26*1_000_000 +  in + curr)%26 ;
                    chars[i] = (char) ( 'a' + off ) ;  
                }else {
                    int in = s.charAt(i) - 'A' ; 
                    long off = (26*1_000_000 +  in + curr)%26 ;
                    chars[i] = (char) ( 'A' + off ) ;  
                }
            }
            curr-- ; 
        }


        System.out.println( new String(chars) ) ; 
        
       }
}
