package main

import "log"




type HuffmanNode struct {
	left  *HuffmanNode
	right *HuffmanNode
	value int
	character string
}

func LeftChild(index int) int {
	return 2*index + 1
}
func RightChild(index int) int {
	return 2*index + 2
}
func Parent(index int) int {
	return (index - 1) / 2
}
type HuffmanMinHeap struct {
	data []HuffmanNode
	Size int
}

func (heap *HuffmanMinHeap) Push(node HuffmanNode) {
	heap.data = append(heap.data, node)

	// Keep swapping to parent unless its less than the new node or we hit the root
	current := len(heap.data) - 1
	for current > 0 && heap.data[Parent(current)].value > heap.data[current].value {
		heap.data[Parent(current)], heap.data[current] = heap.data[current], heap.data[Parent(current)]
		current = Parent(current)
	}
	heap.Size++
}

func (heap *HuffmanMinHeap) Heapify(i int) {
	smallest := i
	left := LeftChild(i)
	right := RightChild(i)
	heapSize := len(heap.data)

	if left < heapSize && heap.data[left].value < heap.data[smallest].value {
		smallest = left
	}
	if right < heapSize && heap.data[right].value < heap.data[smallest].value {
		smallest = right
	}
	if smallest != i {
		heap.data[i], heap.data[smallest] = heap.data[smallest], heap.data[i]
		heap.Heapify(smallest)
	}
}

func (heap *HuffmanMinHeap) Pop() HuffmanNode {
	if heap.Size == 0 {
		log.Fatal("Pop from empty heap")
	}
	root := heap.data[0]
	heap.data[0] = heap.data[len(heap.data)-1]

	heap.data = heap.data[:len(heap.data)-1]
	heap.Size--
	if heap.Size > 0 {
		heap.Heapify(0)
	}
	return root
}

func CreateHuffmanMap(node *HuffmanNode, huffman_map map[string]string, cur_path string) {
	if node == nil {
		return
	}

	if node.character != "" {
		huffman_map[node.character] = cur_path
		return
	}

	CreateHuffmanMap(node.left, huffman_map, cur_path + "0")
	CreateHuffmanMap(node.right, huffman_map, cur_path + "1")

}

func CreateHuffmanGraph(freq_map map[string]int) HuffmanNode{
	pq := HuffmanMinHeap{data: make([]HuffmanNode, 0), Size: 0}
	for key, value := range freq_map {
		pq.Push(HuffmanNode{nil, nil, value, key})
	}

	for pq.Size >= 2 {
		left := pq.Pop()
		right := pq.Pop()

		// Create parent node with the sum of the left and right node values
		parent := HuffmanNode{&left, &right, left.value + right.value, ""}

		// Add back into pq to be used again
		pq.Push(parent)
	}

	root := pq.Pop()
	return root

}

func DecodeHuffman(root *HuffmanNode, encoded string) string {
	decoded := ""
	encoded_index := 0

	for encoded_index < len(encoded) {
		current := root
		for current.character == "" && encoded_index < len(encoded) {
			if encoded[encoded_index] == '1' {
				current = current.right
			} else if encoded[encoded_index] == '0' {
				current = current.left
			}
			encoded_index++
		}
		if current.character != "" {
			decoded += current.character
		}
	}

	return decoded
}

func CountFrequency(str string) map[string]int {
	freq_map := make(map[string]int)

	for i := 0; i < len(str); i++ {
		char := string(str[i])
		if _, ok := freq_map[char]; ok {
			freq_map[char]++
		} else {
			freq_map[char] = 1
		}
	}

	return freq_map
}

func main() {
	input := "aabcdde"
	freq_map := CountFrequency(input)
	root := CreateHuffmanGraph(freq_map)
	huffman_map := make(map[string]string)
	CreateHuffmanMap(&root, huffman_map, "")

	output := ""
	for i := 0; i < len(input); i++ {
		output += huffman_map[string(input[i])]
	}
	log.Println(output, len(output))
	log.Println(DecodeHuffman(&root, output))

}