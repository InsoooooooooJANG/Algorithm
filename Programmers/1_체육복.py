def solution(n, lost, reserve):
    _lost = set(lost) - set(reserve)
    _reserve = set(reserve) - set(lost)

    for i in _reserve:
        front = i-1
        back = i+1

        if front in _lost :
            _lost.remove(front)
            continue
        if back in _lost:
            _lost.remove(back)
            continue


    answer=n-len(_lost)

    return answer