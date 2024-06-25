from datetime import datetime, timedelta

def add_days_to_date(initial_date, days):
    # Converter a data inicial para o formato datetime
    initial_date_obj = datetime.strptime(initial_date, "%Y-%B-%d")

    # Adicionar os dias à data inicial
    result_date_obj = initial_date_obj + timedelta(days=days)

    # Formatar a data resultante de volta para o formato especificado
    result_date_str = result_date_obj.strftime("%Y-%B-%d")

    return result_date_str

num_cases = int(input())

for case_num in range(1, num_cases + 1):
    input_date = input()
    days_to_add = int(input())

    result_date = add_days_to_date(input_date, days_to_add)

    # Output o resultado
    print(f"Case {case_num}: {result_date}")
