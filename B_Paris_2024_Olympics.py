import csv

medal_table = [
    {'code': 'USA', 'gold': 40, 'silver': 44, 'bronze': 42, 'total': 126},
    {'code': 'CHN', 'gold': 40, 'silver': 27, 'bronze': 24, 'total': 90},
    {'code': 'JPN', 'gold': 20, 'silver': 12, 'bronze': 13, 'total': 45},
    {'code': 'AUS', 'gold': 18, 'silver': 19, 'bronze': 16, 'total': 53},
    {'code': 'FRA', 'gold': 16, 'silver': 26, 'bronze': 22, 'total': 64},
    {'code': 'NED', 'gold': 15, 'silver': 7, 'bronze': 12, 'total': 34},
    {'code': 'GBR', 'gold': 14, 'silver': 21, 'bronze': 29, 'total': 64},
    {'code': 'KOR', 'gold': 13, 'silver': 9, 'bronze': 10, 'total': 32},
    {'code': 'ITA', 'gold': 12, 'silver': 13, 'bronze': 13, 'total': 38},
    {'code': 'GER', 'gold': 11, 'silver': 13, 'bronze': 8, 'total': 32},
    {'code': 'NZL', 'gold': 10, 'silver': 7, 'bronze': 3, 'total': 20},
    {'code': 'CAN', 'gold': 9, 'silver': 7, 'bronze': 11, 'total': 27},
    {'code': 'UZB', 'gold': 8, 'silver': 2, 'bronze': 3, 'total': 13},
    {'code': 'HUN', 'gold': 6, 'silver': 7, 'bronze': 6, 'total': 19},
    {'code': 'ESP', 'gold': 5, 'silver': 4, 'bronze': 9, 'total': 18},
    {'code': 'SWE', 'gold': 4, 'silver': 4, 'bronze': 3, 'total': 11},
    {'code': 'KEN', 'gold': 4, 'silver': 2, 'bronze': 5, 'total': 11},
    {'code': 'NOR', 'gold': 4, 'silver': 1, 'bronze': 3, 'total': 8},
    {'code': 'IRL', 'gold': 4, 'silver': 0, 'bronze': 3, 'total': 7},
    {'code': 'BRA', 'gold': 3, 'silver': 7, 'bronze': 10, 'total': 20},
    {'code': 'IRI', 'gold': 3, 'silver': 6, 'bronze': 3, 'total': 12},
    {'code': 'UKR', 'gold': 3, 'silver': 5, 'bronze': 4, 'total': 12},
    {'code': 'ROU', 'gold': 3, 'silver': 4, 'bronze': 2, 'total': 9},
    {'code': 'GEO', 'gold': 3, 'silver': 3, 'bronze': 1, 'total': 7},
    {'code': 'SRB', 'gold': 3, 'silver': 1, 'bronze': 1, 'total': 5},
    {'code': 'BUL', 'gold': 3, 'silver': 0, 'bronze': 3, 'total': 6},
    {'code': 'CZE', 'gold': 3, 'silver': 0, 'bronze': 2, 'total': 5},
    {'code': 'DEN', 'gold': 2, 'silver': 2, 'bronze': 5, 'total': 9},
    {'code': 'AZE', 'gold': 2, 'silver': 2, 'bronze': 3, 'total': 7},
    {'code': 'CRO', 'gold': 2, 'silver': 2, 'bronze': 3, 'total': 7},
    {'code': 'CUB', 'gold': 2, 'silver': 1, 'bronze': 6, 'total': 9},
    {'code': 'BEL', 'gold': 2, 'silver': 1, 'bronze': 5, 'total': 8},
    {'code': 'BRN', 'gold': 2, 'silver': 1, 'bronze': 1, 'total': 4},
    {'code': 'SLO', 'gold': 2, 'silver': 1, 'bronze': 0, 'total': 3},
    {'code': 'TPE', 'gold': 2, 'silver': 0, 'bronze': 5, 'total': 7},
    {'code': 'AUT', 'gold': 2, 'silver': 0, 'bronze': 3, 'total': 5},
    {'code': 'HKG', 'gold': 2, 'silver': 0, 'bronze': 2, 'total': 4},
    {'code': 'PHI', 'gold': 2, 'silver': 0, 'bronze': 2, 'total': 4},
    {'code': 'ALG', 'gold': 2, 'silver': 0, 'bronze': 1, 'total': 3},
    {'code': 'INA', 'gold': 2, 'silver': 0, 'bronze': 0, 'total': 2},
    {'code': 'POL', 'gold': 1, 'silver': 4, 'bronze': 5, 'total': 10},
    {'code': 'ISR', 'gold': 1, 'silver': 4, 'bronze': 1, 'total': 6},
    {'code': 'KAZ', 'gold': 1, 'silver': 3, 'bronze': 3, 'total': 7},
    {'code': 'JAM', 'gold': 1, 'silver': 3, 'bronze': 2, 'total': 6},
    {'code': 'RSA', 'gold': 1, 'silver': 3, 'bronze': 2, 'total': 6},
    {'code': 'THA', 'gold': 1, 'silver': 3, 'bronze': 2, 'total': 6},
    {'code': 'AIN', 'gold': 1, 'silver': 3, 'bronze': 1, 'total': 5},
    {'code': 'ETH', 'gold': 1, 'silver': 3, 'bronze': 0, 'total': 4},
    {'code': 'SUI', 'gold': 1, 'silver': 2, 'bronze': 5, 'total': 8},
    {'code': 'ECU', 'gold': 1, 'silver': 2, 'bronze': 2, 'total': 5},
    {'code': 'POR', 'gold': 1, 'silver': 2, 'bronze': 1, 'total': 4},
    {'code': 'GRE', 'gold': 1, 'silver': 1, 'bronze': 6, 'total': 8},
    {'code': 'ARG', 'gold': 1, 'silver': 1, 'bronze': 1, 'total': 3},
    {'code': 'EGY', 'gold': 1, 'silver': 1, 'bronze': 1, 'total': 3},
    {'code': 'TUN', 'gold': 1, 'silver': 1, 'bronze': 1, 'total': 3},
    {'code': 'BOT', 'gold': 1, 'silver': 1, 'bronze': 0, 'total': 2},
    {'code': 'CHI', 'gold': 1, 'silver': 1, 'bronze': 0, 'total': 2},
    {'code': 'LCA', 'gold': 1, 'silver': 1, 'bronze': 0, 'total': 2},
    {'code': 'UGA', 'gold': 1, 'silver': 1, 'bronze': 0, 'total': 2},
    {'code': 'DOM', 'gold': 1, 'silver': 0, 'bronze': 2, 'total': 3},
    {'code': 'GUA', 'gold': 1, 'silver': 0, 'bronze': 1, 'total': 2},
    {'code': 'MAR', 'gold': 1, 'silver': 0, 'bronze': 1, 'total': 2},
    {'code': 'DMA', 'gold': 1, 'silver': 0, 'bronze': 0, 'total': 1},
    {'code': 'PAK', 'gold': 1, 'silver': 0, 'bronze': 0, 'total': 1},
    {'code': 'TUR', 'gold': 0, 'silver': 3, 'bronze': 5, 'total': 8},
    {'code': 'MEX', 'gold': 0, 'silver': 3, 'bronze': 2, 'total': 5},
    {'code': 'ARM', 'gold': 0, 'silver': 3, 'bronze': 1, 'total': 4},
    {'code': 'COL', 'gold': 0, 'silver': 3, 'bronze': 1, 'total': 4},
    {'code': 'KGZ', 'gold': 0, 'silver': 2, 'bronze': 4, 'total': 6},
    {'code': 'PRK', 'gold': 0, 'silver': 2, 'bronze': 4, 'total': 6},
    {'code': 'LTU', 'gold': 0, 'silver': 2, 'bronze': 2, 'total': 4},
    {'code': 'IND', 'gold': 0, 'silver': 1, 'bronze': 5, 'total': 6},
    {'code': 'MDA', 'gold': 0, 'silver': 1, 'bronze': 3, 'total': 4},
    {'code': 'KOS', 'gold': 0, 'silver': 1, 'bronze': 1, 'total': 2},
    {'code': 'CYP', 'gold': 0, 'silver': 1, 'bronze': 0, 'total': 1},
    {'code': 'FIJ', 'gold': 0, 'silver': 1, 'bronze': 0, 'total': 1},
    {'code': 'JOR', 'gold': 0, 'silver': 1, 'bronze': 0, 'total': 1},
    {'code': 'MGL', 'gold': 0, 'silver': 1, 'bronze': 0, 'total': 1},
    {'code': 'PAN', 'gold': 0, 'silver': 1, 'bronze': 0, 'total': 1},
    {'code': 'TJK', 'gold': 0, 'silver': 0, 'bronze': 3, 'total': 3},
    {'code': 'ALB', 'gold': 0, 'silver': 0, 'bronze': 2, 'total': 2},
    {'code': 'GRN', 'gold': 0, 'silver': 0, 'bronze': 2, 'total': 2},
    {'code': 'MAS', 'gold': 0, 'silver': 0, 'bronze': 2, 'total': 2},
    {'code': 'PUR', 'gold': 0, 'silver': 0, 'bronze': 2, 'total': 2},
    {'code': 'CIV', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
    {'code': 'CPV', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
    {'code': 'EOR', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
    {'code': 'PER', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
    {'code': 'QAT', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
    {'code': 'SGP', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
    {'code': 'SVK', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
    {'code': 'ZAM', 'gold': 0, 'silver': 0, 'bronze': 1, 'total': 1},
]

def calculate_medals_needed_corrected(medal_table, country_code):
    country = next(c for c in medal_table if c['code'] == country_code)
    medals_needed = 0

    while True:
        is_first = True
        for other in medal_table:
            if other['code'] == country_code:
                continue
            if (other['gold'] > country['gold'] or
                (other['gold'] == country['gold'] and other['silver'] > country['silver']) or
                (other['gold'] == country['gold'] and other['silver'] == country['silver'] and other['bronze'] > country['bronze'])):
                is_first = False
                break
        
        if is_first:
            break

        medals_needed += 1
        country['gold'] += 1
        country['silver'] += 1
        country['bronze'] += 1

    return medals_needed
def main():
    country_code = input().strip()
    result = calculate_medals_needed_corrected(medal_table, country_code)
    print(result)

if __name__ == "__main__":
    main()
