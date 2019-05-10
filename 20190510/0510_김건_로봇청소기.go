package awesomeProject
package main

import . "fmt"

func clean (array *[50][50]int, Number1 *int, Number2 *int, Number3 *int) bool{ // 청소 함수
	if array[*Number1][*Number2] == 0{
		array[*Number1][*Number2] = 2
		*Number3++
		return true
	} else{
		return false
	}
}
func noclean (Number1 *int){
	*Number1 = *Number1 +1
}

func noclean_reset (Number1 *int){
	*Number1 = 0
}
func check(array *[50][50]int,Number1 *int, Number2 *int, Number3 *int) bool {

	/////////////// 해당 자리가 비어있는가
	if array[*Number1][*Number2] == 0 {
		return true
	}
	return false
}
func check1 (array *[50][50]int,Number1 *int, Number2 *int, Number3 *int) bool { // Number1 세로 Number2 가로 Number3 바라보는 방향
	if *Number3 == 0{ /// 이동할 자리가 비어있는지 체크하는 함수
		if array[*Number1][*Number2 - 1] == 0{
			// *Number1 = *Number1 -1
			return true
		}
	} else if *Number3 == 1 {
		if array[*Number1 - 1][*Number2] == 0{
			// *Number2 = *Number2 -1
			return true
		}
	} else if *Number3 == 2 {
		if array[*Number1][*Number2 + 1] == 0{
			// *Number1 = *Number1 + 1
			return true
		}
	} else {
		if array[*Number1+1][*Number2] == 0{
			// *Number2 = *Number2 + 1
			return true
		}
	}
	return false
}
/* func check3(array *[50][50]int,Number1 *int, Number2 *int, Number3 *int) bool {
	////////////// 벽인지 검사

}
*/

func move (array *[50][50]int, Number1 *int, Number2 *int, Number3 *int) { // Number1 세로 Number2 가로 Number3 바라보는 방향
	if *Number3 == 0{
		*Number2 = *Number2 - 1
	} else if *Number3 == 1 {
		*Number1 = *Number1 - 1
	} else if *Number3 == 2 {
		*Number2 = *Number2 + 1
	} else { //
		*Number1 = *Number1 + 1
	}
}
func back_move_check(array *[50][50]int, Number1 *int, Number2 *int, Number3 *int) bool { // Number1 세로 Number2 가로 Number3 바라보는방향
	if *Number3 == 0{ /// 이동할 자리가 비어있는지 체크하는 함수
		if array[*Number1 + 1][*Number2] == 1{
			return false
		}
	} else if *Number3 == 1 {
		if array[*Number1][*Number2 - 1] == 1{
			return false
		}
	} else if *Number3 == 2 {
		if array[*Number1 - 1][*Number2] == 1{
			return false
		}
	} else {
		if array[*Number1][*Number2 + 1] == 1{
			return false
		}
	}
	return true
}
func back_move (array *[50][50]int, Number1 *int, Number2 *int, Number3 *int){ // Number1 세로 Number2 가로 Number3 바라보는방향

	if *Number3 == 0{ /// 이동할 자리가 비어있는지 체크하는 함수
		if array[*Number1 + 1][*Number2] == 2{
			*Number1 = *Number1  +1
		}
	} else if *Number3 == 1 {
		if array[*Number1][*Number2 - 1] == 2{
			*Number2 = *Number2 -1
		}
	} else if *Number3 == 2 {
		if array[*Number1 - 1][*Number2] == 2{
			*Number1 = *Number1 - 1
		}
	} else {
		if array[*Number1][*Number2 + 1] == 2{
			*Number2 = *Number2 + 1
		}
	}
}
func move1 (array *[50][50] int, Number1 *int, Number2 *int, Number3 *int)  {
	///////////// vertex가 바뀌어야하는경우
	if *Number3 == 0{
		*Number3 = 3
	} else if *Number3 == 1 {
		*Number3 = 0
	} else if *Number3 == 2 {
		*Number3 = 1
	} else {
		*Number3 = 2
	}
}
func main() {
	var sero, garo int // sero 세로 garo 가로
	var x, y int       // x 세로 위치 y 가로 위치
	var vertex int     // 바라보는 방향
	// println(" 벽에 대한 변수를 입력하세요. ")
	Scanf("%d %d", &sero, &garo)
	// 	Printf("%d %d",sero,garo)
	// println(" 청소기 위치를 입력하세요. ")
	Scanf("%d %d %d", &x, &y, &vertex)
	//println("  청소기 방향을 입력하세요. ") // (0 = 북 1 = 동 2 = 남 3 = 서)
	// Scanf("%d", &vertex)

	var arr [50][50]int // 방 배열 정보
	var Count int       /// 방 정보 받는 변수

	// println(" 방의 정보를 입력하세요. ")
	for i := 0; i < sero; i++ {
		for j := 0; j < garo; j++ {
			Scanf("%d", &Count)
			arr[i][j] = Count
		}
	}

	/*for i := 0; i < sero; i++ {
		for j := 0; j < garo; j++ {
			print(arr[i][j])
		}
		println("")

	}
	*/
	// println("") //// 배열에 들어간 수 체크
	var clean_counter= 0   // 청소 횟수 세는 카운터
	var noclean_counter= 0 // 청소

	for {
		if clean(&arr,&x,&y,&clean_counter) ==true { // 1번 자리자리 청소하기
			noclean_reset(&noclean_counter)
			/*for i := 0; i < sero; i++ {
				for j := 0; j < garo; j++ {
					print(arr[i][j])
				}
				println("")
			}
			println("")
			*/
		}
		if(noclean_counter == 4) {
			if back_move_check(&arr,&x,&y,&vertex) == true{
				back_move(&arr, &x, &y, &vertex) //////////// 후진 함수 구현
				noclean_reset(&noclean_counter)
			}else{
				Println(clean_counter)
				/*for i := 0; i < sero; i++ {
					for j := 0; j < garo; j++ {
						print(arr[i][j])
					}
					println("")
				}
				*/
				return
			}
		}
		switch (vertex) { //// (0 = 북 1 = 동 2 = 남 3 = 서)
		case 0:
			{
				// vertex = 3
				if check1(&arr,&x,&y,&vertex) == true{
					move(&arr,&x,&y,&vertex)
					move1(&arr,&x,&y,&vertex)
				} else{
					noclean(&noclean_counter)
					move1(&arr,&x,&y,&vertex)
				}
			}
		case 1:
			{
				// vertex = 0
				if check1(&arr,&x,&y,&vertex) == true{
					move(&arr,&x,&y,&vertex)
					move1(&arr,&x,&y,&vertex)
				} else{
					noclean(&noclean_counter)
					move1(&arr,&x,&y,&vertex)
				}
			}
		case 2:
			{
				// vertex = 1
				if check1(&arr,&x,&y,&vertex) == true{
					move(&arr,&x,&y,&vertex)
					move1(&arr,&x,&y,&vertex)
				} else{
					noclean(&noclean_counter)
					move1(&arr,&x,&y,&vertex)
				}
			}
		case 3:
			{
				// vertex = 2
				if check1(&arr,&x,&y,&vertex) == true{
					move(&arr,&x,&y,&vertex)
					move1(&arr,&x,&y,&vertex)
				} else{
					noclean(&noclean_counter)
					move1(&arr,&x,&y,&vertex)
				}
			}
		}
	}
}