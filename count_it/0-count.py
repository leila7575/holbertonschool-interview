#!/usr/bin/python3
"""contains count words function"""


import requests
import string


def count_words(subreddit, word_list, count=None, after=None):
    """queries reddit API and returns sorted list of words and their count"""

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'python:count_words'}
    params = {'limit': 100}
    if after:
        params['after'] = after

    response = requests.get(
        url, headers=headers, params=params, allow_redirects=False
    )

    data = response.json().get("data", {})
    children_posts = data.get("children", [])

    if count is None:
        count = {}
        word_list = [word.lower() for word in word_list]
        for word in word_list:
            count[word] = 0

    for post in children_posts:
        title = post["data"]["title"]
        title = title.lower().translate(
            str.maketrans('', '', string.punctuation)
        )
        words = title.split()
        for word in words:
            if word in count:
                count[word] += 1

    after = data.get("after")
    if after:
        return count_words(subreddit, word_list, count, after)

    filtered_words = []
    for word, value in count.items():
        if value > 0:
            filtered_words.append((word, value))

    sorted_words = sorted(filtered_words,  key=lambda x: (-x[1], x[0]))

    for word, value in sorted_words:
        print(f"{word}: {value}")
