import math

def calculate_angle(hours, minutes):
    if hours == 12:
        hours = 0  # Converte 12 horas para 0 para facilitar calculo

    # Calculando os ângulos dos ponteiros
    hour_angle = (hours * 30) + (minutes * 0.5)  # 30 graus por hora, 0.5 graus por minuto
    minute_angle = minutes * 6  # 6 graus por minuto

    # Calculando o ângulo entre os ponteiros
    angle = abs(hour_angle - minute_angle)
    angle = min(angle, 360 - angle)  # Ângulo menor entre os dois possíveis

    return angle

def process_input():
    angles = []
    while True:
        time_str = input()
        if time_str == '0:00':
            break
        hours, minutes = map(int, time_str.split(':'))
        angle = calculate_angle(hours, minutes)
        angles.append(angle)
    return angles

result = process_input()

for angle in result:
    print(f'{angle:.3f}')
