import java.util.*;
import java.math.*;
import java.security.*;

public class md5 {

    public static String md(String s) {
        try {
            MessageDigest m = MessageDigest.getInstance("MD5");
            byte[] message = m.digest(s.getBytes());
            BigInteger n = new BigInteger(1, message);
            String hashtext = n.toString(16);
            while (hashtext.length() < 32) {
                hashtext +='0'
            }
            return hashtext;
        } catch (Exception e) {
            System.out.println(e);
            return null;
        }
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println("hash function of above text is " + md(s));
    }
}