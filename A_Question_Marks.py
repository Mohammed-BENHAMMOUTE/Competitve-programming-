def solve_test_case():
    n = int(input())
    s = input()
    
    count = {'A': 0, 'B': 0, 'C': 0, 'D': 0}
    question_marks = 0
    
    for c in s:
        if c == '?':
            question_marks += 1
        else:
            count[c] += 1
    
    if question_marks == 4*n:  # All questions are unanswered
        return 0
    
    correct = 0
    available = {'A': 0, 'B': 0, 'C': 0, 'D': 0}
    
    for letter in 'ABCD':
        correct += min(count[letter], n)
        if count[letter] < n:
            available[letter] = n - count[letter]
    
    additional_correct = 0
    for _ in range(question_marks):
        max_available = max(available.values())
        if max_available > 0:
            for letter in 'ABCD':
                if available[letter] == max_available:
                    available[letter] -= 1
                    additional_correct += 1
                    break
    
    return correct + additional_correct

t = int(input())
for _ in range(t):
    print(solve_test_case())