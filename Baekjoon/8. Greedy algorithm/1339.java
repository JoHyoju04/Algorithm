import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Integer[] alpha = new Integer[26]; //알파벳수만큼 배열 선언

        Arrays.fill(alpha, 0);

        for(int i=0; i<n; i++) {
            char input[] = br.readLine().toCharArray();
            int pos = 1;

            for(int j = input.length -1; j>=0; j--) { //뒤에서 부터 자릿수 증가시키기
                alpha[input[j] - 'A'] += Integer.valueOf(pos);
                pos*=10; //자릿수 증가
            }
        }

        //Collections.reverseOrder를 사용하기 위해서는 Integer로 배열을 선언해야 한다.
        Arrays.sort(alpha, Collections.reverseOrder());

        int value = 9, answer = 0;

        for(int i=0; i<alpha.length; i++) {
            if(alpha[i] == 0) { //더이상 계산할 단어가 없으면 종료
                break;
            }
            answer += alpha[i] * value--;
        }

        System.out.println(answer);

    }
}