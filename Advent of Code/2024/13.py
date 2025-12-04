import hexaly.optimizer

ans = 0
with open("/home/bprevost/Competitive-Programming/Advent of Code/1.in") as f:
    while True:
        lineA = f.readline()
        if not lineA: break
        lineA = lineA.split('X')[1].split(',')
        xA = int(lineA[0].split('+')[1].strip())
        yA = int(lineA[1].split('+')[1].strip())

        lineB = f.readline()
        lineB = lineB.split('X')[1].split(',')
        xB = int(lineB[0].split('+')[1].strip())
        yB = int(lineB[1].split('+')[1].strip())

        lineP = f.readline()
        lineP = lineP.split('X')[1].split(',')
        xP = int(lineP[0].split('=')[1].strip())
        yP = int(lineP[1].split('=')[1].strip())

        line = f.readline()

        with hexaly.optimizer.HexalyOptimizer() as optimizer:
            model = optimizer.model

            a = model.int(0, 10000000000000)
            b = model.int(0, 10000000000000)

            model.constraint( a * xA + b * xB == 10000000000000 + xP)
            model.constraint( a * yA + b * yB == 10000000000000 + yP)

            cost = 3 * a + b
            model.minimize(cost)
            model.close()

            # optimizer.get_param().set_verbosity(0)
            optimizer.save_environment("model.hxb.gz")
            optimizer.solve()

            optimizer.compute_inconsistency()

            if optimizer.get_solution().get_status() != hexaly.optimizer.HxSolutionStatus.INCONSISTENT:
                ans += cost.get_value()

        done += 1

print(ans)
print(done)