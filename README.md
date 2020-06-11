# Effective-network-topology
Calculates the effective network topology with restrictions on the geographical coordinates of nodes,
just place the coordinates of the nodes in degrees in the file ("input.txt" by default) in this format:
<latitude> <longitude> <comments>

Parameters:
        -i   Input file, default "input.txt"
        -o   Output file, default "out.txt"
        -l   Sets a limit, the number of nodes in the segment will not exceed it (default limit <4)
