# TODO
def main():
    text = input("Text: ")

    cnt_l = count_letters(text)
    cnt_w = count_words(text)
    cnt_s = count_sentences(text)
    l = cnt_l / cnt_w * 100
    s = cnt_s / cnt_w * 100.0
    index = round(0.0588 * l - 0.296 * s - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def count_letters(text):
    cnt = 0
    length = len(str(text))
    for i in range(length):
        if text[i].isalnum():
            cnt += 1
    return cnt


def count_words(text):
    cnt = 0
    length = len(str(text))
    for i in range(length):
        if text[i].isspace():
            cnt += 1
    return cnt + 1


def count_sentences(text):
    cnt = 0
    length = len(str(text))
    for i in range(length):
        if text[i] in ['.', '!', '?']:
            cnt += 1
    return cnt


if __name__ == "__main__":
    main()
