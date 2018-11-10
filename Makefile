.DEFAULT_GOAL:=basic

basic: cr
	
RUNFILE =./rt
INPUT1 =./sample_input/spheres.txt
INPUT2 =./sample_input/sphere.txt
OUTPUT =./img.ppm

cr: create run

create:
	g++ rt.cpp Vector.cpp Sphere.cpp Light.cpp -lm -o $(RUNFILE)

run: run1

run1:
	$(RUNFILE) < $(INPUT1) > $(OUTPUT)

run2:
	$(RUNFILE) < $(INPUT2) > $(OUTPUT)

clean:
	rm -rf $(RUNFILE) $(OUTPUT)
