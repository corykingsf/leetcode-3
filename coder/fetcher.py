import requests
from pipetools import pipe, where, X, foreach

from coder.model import Problem, Difficulty


def fetch_problem_list():

    url = 'https://leetcode-cn.com/api/problems/all/'

    r = requests.get(url)
    r.raise_for_status()

    data = r.json()

    def item_to_problem(item):
        id = item['stat']['question_id']
        title = item['stat']['question__title']
        title_slug = item['stat']['question__title_slug']
        difficulty = item['difficulty']['level']
        paid_only = item['paid_only']
        problem = Problem(id=id,
                          title=title,
                          title_slug=title_slug,
                          difficulty=Difficulty(difficulty),
                          paid_only=paid_only)
        return problem

    problems = list(
            data['stat_status_pairs'] > pipe
            | foreach(item_to_problem)
            | where(X.id < 10000)
    )
    return problems