cards = {
    '2N': 1, '2B': 2, '2R': 3, '2C': 4,
    '3N': 5, '3B': 6, '3R': 7, '3C': 8,
    '4N': 9, '4B': 10, '4R': 11, '4C': 12,
    '5N': 13, '5B': 14, '5R': 15, '5C': 16,
    '6N': 17, '6B': 18, '6R': 19, '6C': 20,
    '7N': 21, '7B': 22, '7R': 23, '7C': 24,
    '8N': 25, '8B': 26, '8R': 27, '8C': 28,
    '9N': 29, '9B': 30, '9R': 31, '9C': 32,
    'TN': 33, 'TB': 34, 'TR': 35, 'TC': 36,
    'JN': 37, 'JB': 38, 'JR': 39, 'JC': 40,
    'QN': 41, 'QB': 42, 'QR': 43, 'QC': 44,
    'KN': 45, 'KB': 46, 'KR': 47, 'KC': 48,
    'AN': 49, 'AB': 50, 'AR': 51, 'AC': 52,
}


def Input():
    Adam_Cards = []
    Eva_Cards = []
    temp = []
    with open('CARD.INP', 'r') as input:
        n_tests = int(input.readline())

        count = 0
        while count < n_tests:
            n_cards = input.readline()
            if n_cards == '\n':
                continue

            temp.append(int(n_cards.strip()))
            temp_adam = []
            temp_eva = []

            for j in range(temp[count]):
                temp_adam.append(cards[input.readline().strip()])
            Adam_Cards.append(temp_adam)

            for j in range(temp[count]):
                temp_eva.append(cards[input.readline().strip()])
            Eva_Cards.append(temp_eva)

            count += 1

    return n_tests, Adam_Cards, Eva_Cards

def MaxPoints(adam, eva):
    eva = sorted(eva, reverse=True)
    adam = sorted(adam, reverse=True)
    points = 0
    k = 0
    for i in range(len(adam)):
        for j in range(k, len(eva)):
            if adam[i] < eva[j]:
                k = j + 1
                points += 1
                break
    return points


with open('CARD.OUT', 'w') as output:
    n, Adam, Eva = Input()
    for i in range(n):
        output.write(str(MaxPoints(Adam[i], Eva[i])) + '\n')
    
